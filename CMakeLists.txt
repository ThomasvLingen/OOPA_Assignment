cmake_minimum_required(VERSION 3.3)
project(OOPA_CircuitSim)

set(CMAKE_CXX_COMPILER /usr/bin/g++-4.9)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_SOURCE_DIR})

set(SOURCE_FILES
    main.cpp
    CircuitParsing/Lexeme.hpp CircuitParsing/Lexeme.cpp
    CircuitParsing/Stage1Lexer.hpp CircuitParsing/Stage1Lexer.cpp
    CircuitUtility/StrUtil.hpp CircuitUtility/StrUtil.cpp
    CircuitParsing/Stage1LexemePool.hpp CircuitParsing/Stage1LexemePool.cpp
    CircuitParsing/LexemePool.hpp CircuitParsing/LexemePool.cpp
    CircuitParsing/Stage2Lexer.hpp CircuitParsing/Stage2Lexer.cpp
    CircuitParsing/Stage2LexemePool.hpp CircuitParsing/Stage2LexemePool.cpp
    CircuitParsing/InputFileNode.hpp CircuitParsing/InputFileNode.cpp
    CircuitParsing/InputFileData.hpp CircuitParsing/InputFileData.cpp
    CircuitParsing/CircuitParser.hpp CircuitParsing/CircuitParser.cpp
    Circuit/NodeTypes.hpp Circuit/NodeTypes.cpp
    Circuit/Observed.hpp Circuit/Observed.cpp
    Circuit/Observer.hpp Circuit/Observer.cpp
    FactoryTest/GateFactory.hpp FactoryTest/GateFactory.cpp
    FactoryTest/Gate.hpp FactoryTest/Gate.cpp
    FactoryTest/AndGate.hpp FactoryTest/AndGate.cpp
    FactoryTest/OrGate.hpp FactoryTest/OrGate.cpp
    Circuit/Nodes/Node.hpp Circuit/Nodes/Node.cpp
    Circuit/Nodes/AndGate.hpp Circuit/Nodes/AndGate.cpp
    Circuit/Nodes/InputHigh.hpp Circuit/Nodes/InputHigh.cpp
)

add_executable(OOPA_CircuitSim ${SOURCE_FILES})
