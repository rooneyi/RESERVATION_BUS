cmake_minimum_required(VERSION 3.28)
project(RESERVATION_BUS C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(RESERVATION_BUS
        main.c
        menu.c
        menu.h
        operation.c
        operation.h
        operation_bus.c
        operation_bus.h
        starter_bus.c
        starter_bus.h)
