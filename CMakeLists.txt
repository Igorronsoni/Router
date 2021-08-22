cmake_minimum_required(VERSION 3.1)
project(Router C)
add_library(sources
  implementation/terminal.c
)
include_directories(include)

add_executable(Router implementation/router.c)