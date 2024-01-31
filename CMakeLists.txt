cmake_minimum_required(VERSION 3.22)
project(large_prime_numbers)

set(CMAKE_CXX_STANDARD 17)

set(Boost_INCLUDE_DIR "../../../../Program Files/Boost/boost_1_84_0")
set(Boost_LIBRARY_DIR "../../../../Program Files/Boost/boost_1_84_0/libs")

find_package(Boost 1.84.0)

include_directories(${Boost_INCLUDE_DIRS})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

add_executable(large_prime_numbers main.cpp fast_pow.cpp gcd.cpp miller_rabin.cpp)
