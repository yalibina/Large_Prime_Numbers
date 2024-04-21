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
FetchContent_MakeAvailable(boost_mult)

add_executable(large_prime_numbers main.cpp fast_pow.cpp gcd.cpp miller_rabin.cpp)
target_link_libraries(large_prime_numbers PUBLIC boost_multiprecision)
