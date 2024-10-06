cmake_minimum_required(VERSION 3.5)

project(morpion)

# Spécifie le standard C
set(CMAKE_C_STANDARD 99)

add_executable(morpion main.c morpion.c)