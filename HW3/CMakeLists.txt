cmake_minimum_required (VERSION 3.10)

project(HW3)

add_executable(main main.c)

add_custom_target(run COMMAND main)

