cmake_minimum_required(VERSION 3.20)

project(ds_alg)

set(CMAKE_C_STANDARD 17)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_subdirectory(benchmark)
add_subdirectory(ADT)

add_executable(intarr intarr/main.c)
add_executable(collatz collatz/main.c)
add_executable(evensort evensort/main.c)
add_executable(arrayshift arrayshift/main.c)
add_executable(sum_of_products sum_of_products/main.c)
add_executable(linkedlist lab7_linked_list/main.c)
add_executable(priorityqueue lab8_priority_queue/main.c)
add_executable(lab6
        lab6/main.c
        lab6/HeapSort.c
        lab6/InsertionSort.c
        lab6/MergeSort.c
        lab6/QuickSort.c
        lab6/SelectionSort.c
        lab6/Utils.c
)
target_include_directories(linkedlist PRIVATE ADT)
target_link_libraries(linkedlist PRIVATE ADT)
target_include_directories(lab6 PRIVATE benchmark)
target_include_directories(arrayshift PRIVATE benchmark)
target_include_directories(sum_of_products PRIVATE benchmark)
target_link_libraries(lab6 PRIVATE benchmark)
target_link_libraries(arrayshift PRIVATE benchmark)
target_link_libraries(sum_of_products PRIVATE benchmark)
