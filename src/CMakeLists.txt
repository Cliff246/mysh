set(SRC ${SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/language.c
)

find_package(Curses REQUIRED)



add_executable(mysh ${SRC})
add_library(Curses::Curses INTERFACE IMPORTED)
target_compile_options(mysh PRIVATE -g -Wall)