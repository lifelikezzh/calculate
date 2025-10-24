cmake_minimum_required(VERSION 4.0)
project(caculate C)

set(CMAKE_C_STANDARD 99)

add_executable(caculate main.c
        isLegal.c
        factorial.c
        clip.c
        PracticalTools.c
        ConvertDecimals.c
        bracket.c
        calculate.c
        TurntoChar.c)
