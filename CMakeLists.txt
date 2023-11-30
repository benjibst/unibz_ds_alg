cmake_minimum_required(VERSION 3.20)
project(ds_alg)
set(CMAKE_C_STANDARD 17)
add_executable(intarr intarr/main.c)
add_executable(collatz collatz/main.c)
add_executable(evensort evensort/main.c)
add_executable(arrayshift arrayshift/main.c)

