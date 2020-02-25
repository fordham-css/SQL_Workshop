# CMakeList.txt : CMake project for Sqlite_Demo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Sqlite_Demo")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Add source to this project's executable.
add_executable (sqlite_demo "sqlite_demo.cpp" "sqlite3.c" "sqlite3.h" "sqlite3ext.h" "IAccountingSystem.hpp")
add_executable(sqlite_shell "shell.c" "sqlite3.c" "sqlite3.h" "sqlite3ext.h")

# TODO: Add tests and install targets if needed.
