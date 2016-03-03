cmake_minimum_required(VERSION 3.3)
project(OOPA_CircuitSim)

set(CMAKE_CXX_COMPILER /usr/bin/g++-4.9)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    CircuitParsing/Lexeme.hpp CircuitParsing/Lexeme.cpp
    CircuitParsing/Stage1Lexer.hpp CircuitParsing/Stage1Lexer.cpp
    CircuitUtility/StrUtil.cpp CircuitUtility/StrUtil.hpp
    CircuitParsing/Stage1LexemePool.hpp CircuitParsing/Stage1LexemePool.cpp
)

add_executable(OOPA_CircuitSim ${SOURCE_FILES})
