cmake_minimum_required(VERSION 3.3)
project(OOPA_CircuitSim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_SOURCE_DIR})

set(SOURCE_FILES
    main.cpp
    CircuitParsing/Lexeme.hpp                       CircuitParsing/Lexeme.cpp
    CircuitParsing/Stage1Lexer.hpp                  CircuitParsing/Stage1Lexer.cpp
    CircuitParsing/Stage1LexemePool.hpp             CircuitParsing/Stage1LexemePool.cpp
    CircuitParsing/LexemePool.hpp                   CircuitParsing/LexemePool.cpp
    CircuitParsing/Stage2Lexer.hpp                  CircuitParsing/Stage2Lexer.cpp
    CircuitParsing/Stage2LexemePool.hpp             CircuitParsing/Stage2LexemePool.cpp
    CircuitParsing/InputFileNode.hpp                CircuitParsing/InputFileNode.cpp
    CircuitParsing/InputFileData.hpp                CircuitParsing/InputFileData.cpp
    CircuitParsing/CircuitParser.hpp                CircuitParsing/CircuitParser.cpp
    CircuitUtility/StrUtil.hpp                      CircuitUtility/StrUtil.cpp
    Circuit/NodeTypes.hpp                           Circuit/NodeTypes.cpp
    Circuit/Observed.hpp                            Circuit/Observed.cpp
    Circuit/Observer.hpp                            Circuit/Observer.cpp
    Circuit/Circuit.hpp                             Circuit/Circuit.cpp
    Circuit/Nodes/Node.hpp                          Circuit/Nodes/Node.cpp
    Circuit/Nodes/Gate.hpp                          Circuit/Nodes/Gate.cpp
    Circuit/Nodes/AndGate.hpp                       Circuit/Nodes/AndGate.cpp
    Circuit/Nodes/NotGate.hpp                       Circuit/Nodes/NotGate.cpp
    Circuit/Nodes/OrGate.hpp                        Circuit/Nodes/OrGate.cpp
    Circuit/Nodes/Input.hpp                         Circuit/Nodes/Input.cpp
    Circuit/Nodes/InputHigh.hpp                     Circuit/Nodes/InputHigh.cpp
    Circuit/Nodes/InputLow.hpp                      Circuit/Nodes/InputLow.cpp
    Circuit/Nodes/Probe.hpp                         Circuit/Nodes/Probe.cpp
    Circuit/NodeFactory.hpp                         Circuit/NodeFactory.cpp
    Circuit/CircuitVisitors/CircuitVisitor.hpp      Circuit/CircuitVisitors/CircuitVisitor.cpp
    Circuit/CircuitVisitors/CircuitStatsVisitor.hpp Circuit/CircuitVisitors/CircuitStatsVisitor.cpp
    Circuit/CircuitVisitors/UnconnectedVisitor.hpp  Circuit/CircuitVisitors/UnconnectedVisitor.cpp
)

add_executable(OOPA_CircuitSim ${SOURCE_FILES})
