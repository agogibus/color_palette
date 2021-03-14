cmake_minimum_required(VERSION 3.16)
project(palette)

set(SRCS srcs/bmp.c srcs/main.c srcs/image.c)

add_executable(palette ${SRCS})