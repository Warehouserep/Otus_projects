cmake_minimum_required(VERSION 3.10)

project(Blockchain CXX)

add_executable(Blockchain
    Blockchain/src/Block.cpp
    Blockchain/src/Blockchain.cpp
    Blockchain/src/main.cpp
    Blockchain/include/Block.h
    Blockchain/include/Blockchain.h
    Blockchain/include/TransactionData.h
)

target_include_directories(Blockchain PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(Blockchain PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Blockchain PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(Blockchain PUBLIC cxx_std_17)