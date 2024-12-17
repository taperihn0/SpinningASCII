cmake_minimum_required(VERSION 3.20)

project(SpinASCII)

add_executable(SpinASCII main.c)

find_library(MATH_LIBRARY m)
if (MATH_LIBRARY)
	target_link_libraries(SpinASCII PUBLIC ${MATH_LIBRARY})
endif()

set(FLAGS -Wall -O2)
target_compile_options(SpinASCII PRIVATE ${FLAGS})