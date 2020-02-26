# CMakeList.txt : CMake project for Sqlite_Demo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Sqlite_Demo")

# Add source to this project's executable.
add_executable (create_table "create_table.c")
add_executable(insert_data "insert_data.c")
add_executable(select_data "select_data.c")
# add_executable(sqlite_shell "shell.c" "sqlite3.c" "sqlite3.h" "sqlite3ext.h")

TARGET_LINK_LIBRARIES(sqlite_demo pthread dl sqlite3)
TARGET_LINK_LIBRARIES(insert_data pthread dl sqlite3)
TARGET_LINK_LIBRARIES(select_data pthread dl sqlite3)

# TODO: Add tests and install targets if needed.
