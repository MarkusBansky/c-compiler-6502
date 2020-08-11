cmake_minimum_required(VERSION 3.17)
project(cassowary_6502)

add_library(cassowary_6502 STATIC sources/cassowary_6502.c)

install(TARGETS cassowary_6502 DESTINATION lib)
install(FILES sources/cassowary_6502.h DESTINATION include)
