cmake_minimum_required(VERSION 3.23)
project(pharmacyManagementSystem C)

set(CMAKE_C_STANDARD 23)

add_executable(pharmacyManagementSystem main.c customer.h customer.c functions.c functions.h pharmacist.h pharmacist.c pharmacist.c pharmacist.h headers.h)
