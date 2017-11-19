cmake_minimum_required(VERSION 3.8.1)


set(OTHER_FILES_EXTENSION "")

set (PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

	# thiet lap o day
	set(PROJECT_NAME "project")

	set(SOURCE_FOLDER "src")
	set(INCLUDE_FOLDER "include")
	set(OUTPUT_FOLDER "bin")

	# vs only settings
	set(OTHER_FILES_FOLDER "bin")

	set(DEBUG_FOLDER "bin") # vs only

# output file exe location
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../${OUTPUT_FOLDER})

# the project name
project (${PROJECT_NAME} CXX)

# The version number.
set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)
set (VERSION_FIX 0)
configure_file (
  "${PROJECT_SOURCE_DIR}/${SOURCE_FOLDER}/version.h.in"
  "${PROJECT_SOURCE_DIR}/${SOURCE_FOLDER}/version.h"
)


if (USEBOOST)

set(BOOST_INCLUDEDIR "C:/Program Files/boost/include/boost-1_65_1")
set(BOOST_LIBRARYDIR "C:/Program Files/boost/lib")

include_directories(${BOOST_INCLUDEDIR})
endif() # use_boost

# the included folder for <foo.h>
include_directories(${INCLUDE_FOLDER})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
# using Clang
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")



set(WARNING "-Wall")
set(PUBLIC "-static -static-libgcc -static-libstdc++")
set(IDENTIFIER "-fextended-identifiers --input-charset=utf-8 -finput-charset=utf-8 --exec-charset=utf-8")
set(CPPVERSION "-std=c++11")

set(CMAKE_CXX_FLAGS ${WARNING}\ ${PUBLIC}\ ${IDENTIFIER}\ ${CPPVERSION})

	if(TEST)
		add_definitions(-DUNITTEST)
		set (google_test "${PROJECT_ROOT_DIR}/include/googletest")
		include_directories(${google_test})
		include_directories(${google_test}/include)
		add_subdirectory("test")
	else(TEST)
		add_subdirectory("src")
	endif(TEST)

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
# using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")

	# the included folder for <foo.h>
	include_directories(${INCLUDE_FOLDER})
	file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${SOURCE_FOLDER}/*.cpp")
	file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${INCLUDE_FOLDER}/*.h" "${INCLUDE_FOLDER}/*.hpp")
	file(GLOB_RECURSE RESOURCE RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${OTHER_FILES_FOLDER}/*.${OTHER_FILES_EXTENSION}")

	set(ALL_FILES ${SOURCES}\  ${HEADERS}\  ${RESOURCE})
	add_executable(${PROJECT_NAME} ${ALL_FILES})



	# using filter in VS
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	# tạo folder cho project
	foreach(FILE ${ALL_FILES})
		get_filename_component(PARENT_DIR "${FILE}" PATH)

		# skip src or include and changes /'s to \\'s
		string(REGEX REPLACE "(\\./)?(${SOURCE_FOLDER}|${INCLUDE_FOLDER}|${OTHER_FILES_FOLDER})/?" "" GROUP "${PARENT_DIR}")
		string(REPLACE "/" "\\" GROUP "${GROUP}")

		# group into "Source Files" and "Header Files"
		if ("${FILE}" MATCHES ".*\\.cpp")
			set(GROUP "Source Files\\${GROUP}")
		elseif("${FILE}" MATCHES ".*\\.h")
			set(GROUP "Header Files\\${GROUP}")
		elseif("${FILE}" MATCHES ".*\\.${OTHER_FILES_EXTENSION}")
			set(GROUP "Resource Files\\${GROUP}")
		endif()

		source_group("${GROUP}" FILES "${FILE}")
	endforeach()

	# thư mục khi chạy Debug
	set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/${DEBUG_FOLDER}")
endif()
