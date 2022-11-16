cmake_minimum_required(VERSION 3.23)
project(pharmacyManagementSystem C)

set(CMAKE_C_STANDARD 23)

add_executable(pharmacyManagementSystem main.c customer/customer.h customer/customer.c functions.c functions.h pharmacist/pharmacist.h pharmacist/pharmacist.c pharmacist/pharmacist.c pharmacist/pharmacist.h headers.h)
