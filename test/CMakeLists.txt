set (SOME_TEST
      "demo.cpp"
)

add_library (TESTING OBJECT ${SOME_TEST})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../src ${CMAKE_CURRENT_BINARY_DIR}/src)