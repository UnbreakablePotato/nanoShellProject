cmake_minimum_required(VERSION 3.15)
project(MyProject LANGUAGES CXX)

# Use C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Automatically collect all .cpp files in the project root
file(GLOB SOURCES *.cpp)

# Create the executable
add_executable(myapp ${SOURCES})

find_library(READLINE_LIBRARY readline)
find_path(READLINE_INCLUDE_DIR readline/readline.h)

target_include_directories(myapp PRIVATE ${READLINE_INCLUDE_DIR})
find_library(READLINE_LIBRARY readline)
find_library(NCURSESW_LIBRARY ncursesw)

target_link_libraries(myapp PRIVATE
    ${READLINE_LIBRARY}
    ${NCURSESW_LIBRARY}
)

#when changes are made to this file run the command: cmake -B build -S
#When changes have not been made just run: cmake --build build
#Then ./build/myapp
