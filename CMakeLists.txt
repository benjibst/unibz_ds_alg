cmake_minimum_required(VERSION 3.20)

project(ds_alg)

set(CMAKE_C_STANDARD 17)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(intarr intarr/main.c)
add_executable(collatz collatz/main.c)
add_executable(evensort evensort/main.c)
add_executable(arrayshift arrayshift/main.c)
add_executable(merge_sort merge_sort/main.c)
add_executable(sum_of_products sum_of_products/main.c)
target_include_directories(merge_sort PUBLIC utils)
target_include_directories(sum_of_products PUBLIC utils)
