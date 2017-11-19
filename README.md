# PROJECT

## About

This is a prebuilt program by Nguyen Anh Khoa aka Luibo

This program is a mere console C++ program with

* unit test by [google test](https://github.com/google/googletest/tree/master/googletest)
* logging system by [spdlog](https://github.com/gabime/spdlog)
* format definitions in [.clang-format](clang.llvm.org/docs/ClangFormatStyleOptions.html)

Future update will get 

* [ ] [Google Mock](https://github.com/google/googletest/tree/master/googlemock)
* [ ] [Boost](www.boost.org)
* [ ] ... may someone recommend me ...

For best experience, use [Visual Studio Code](https://code.visualstudio.com/)

## Licensing

I don't know about licensing

Will update in future

---

#### BUILD HELP

* for mingw user

```
for debug
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug

for release
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release

for test with debug
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug -DTEST=ON

for test with release
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DTEST=ON
```

* for clang user

```
to be updated
```

* for Visual Studio user

```
used to be able to create project files for Visual Studio
but now not sure
i dont have Visual Studio to test on
run this to build for Visual Studio

I don't know how to make Visual Studio create a test build
Maybe in future I will try to make the recipe

for debug
cmake -G "Visual Studio <Version number>" -DCMAKE_BUILD_TYPE=Debug

for release
cmake -G "Visual Studio <Version number>" -DCMAKE_BUILD_TYPE=Release

for test with debug
cmake -G "Visual Studio <Version number>" -DCMAKE_BUILD_TYPE=Debug -DTEST=ON

for test with release
cmake -G "Visual Studio <Version number>" -DCMAKE_BUILD_TYPE=Release -DTEST=ON



| Visual Studio | Vesion number |
|---------------|---------------|
| 2005          | 8             |
| 2008          | 9             |
| 2010          | 10            |
| 2012          | 11            |
| 2013          | 12            |
| 2015          | 14            |
| 2017          | 15            |
```


* Other build files

```
Not yet configured
```


#### Note

This program is only for Windows and Linux console only

This program is not (yet) configured for OS