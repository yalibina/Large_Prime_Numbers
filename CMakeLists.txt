cmake_minimum_required(VERSION 3.22)
project(large_prime_numbers)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_INCLUDE_LIBRARIES multiprecision)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
FetchContent_Declare(
        boost_mult
        GIT_REPOSITORY https://github.com/boostorg/multiprecision.git
        GIT_TAG cc9e01d584abc614d6fbeb4a8da0b44293ef2ef7
        GIT_SHALLOW TRUE

)

FetchContent_Declare(
        magic_enum
        GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
        GIT_TAG e55b9b54d5cf61f8e117cafb17846d7d742dd3b4
        GIT_SHALLOW TRUE

)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# for Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(boost_mult magic_enum googletest)

add_executable(large_prime_numbers main.cpp utilities/fast_pow.cpp utilities/gcd.cpp miller_rabin.cpp lucas_lehmer.cpp fermat.cpp
        factorization/trial_division.cpp factorization/pollard.cpp factorization/fermat_factor.cpp utilities/int_sqrt.cpp utilities/reduce.cpp
        trial_division_test.cpp
        trial_division_test.h)

target_link_libraries(large_prime_numbers PRIVATE boost_multiprecision magic_enum)

include(tests/sources.cmake)

enable_testing()

target_link_libraries(tests GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(tests)