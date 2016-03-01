cmake_minimum_required(VERSION 3.3)
project(OOPA_CircuitSim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    CircuitParsing/Lexeme.hpp CircuitParsing/Lexeme.cpp
    CircuitParsing/Stage1Lexer.hpp CircuitParsing/Stage1Lexer.cpp
    CircuitUtility/StrUtil.hpp CircuitUtility/StrUtil.cpp
    FactoryTest/GateFactory.hpp FactoryTest/GateFactory.cpp
    FactoryTest/Gate.hpp FactoryTest/Gate.cpp
    FactoryTest/AndGate.hpp FactoryTest/AndGate.cpp
)

add_executable(OOPA_CircuitSim ${SOURCE_FILES})
