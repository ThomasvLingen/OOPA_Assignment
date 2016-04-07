cmake_minimum_required(VERSION 2.8.2)

project(OOPA_test)

include(CTest)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()

# Trivial example using gtest and gmock
set(OOPA_SRC
    ${OOPA_test_SOURCE_DIR}/../Circuit/CircuitSimulator.hpp ${OOPA_test_SOURCE_DIR}/../Circuit/CircuitSimulator.cpp
    ${OOPA_test_SOURCE_DIR}/../CircuitParsing/Lexeme.hpp ${OOPA_test_SOURCE_DIR}/../CircuitParsing/Lexeme.cpp
    ${OOPA_test_SOURCE_DIR}/../CircuitParsing/Stage1Lexer.hpp                  ${OOPA_test_SOURCE_DIR}/../CircuitParsing/Stage1Lexer.cpp
    ${OOPA_test_SOURCE_DIR}/../CircuitParsing/Stage1LexemePool.hpp             ${OOPA_test_SOURCE_DIR}/../CircuitParsing/Stage1LexemePool.cpp
    ${OOPA_test_SOURCE_DIR}/../CircuitParsing/LexemePool.hpp                   ${OOPA_test_SOURCE_DIR}/../CircuitParsing/LexemePool.cpp
    ${OOPA_test_SOURCE_DIR}/../CircuitParsing/Stage2Lexer.hpp                  ${OOPA_test_SOURCE_DIR}/../CircuitParsing/Stage2Lexer.cpp
    ${OOPA_test_SOURCE_DIR}/../CircuitParsing/Stage2LexemePool.hpp             ${OOPA_test_SOURCE_DIR}/../CircuitParsing/Stage2LexemePool.cpp
    ${OOPA_test_SOURCE_DIR}/../CircuitParsing/InputFileNode.hpp                ${OOPA_test_SOURCE_DIR}/../CircuitParsing/InputFileNode.cpp
    ${OOPA_test_SOURCE_DIR}/../CircuitParsing/InputFileData.hpp                ${OOPA_test_SOURCE_DIR}/../CircuitParsing/InputFileData.cpp
    ${OOPA_test_SOURCE_DIR}/../CircuitParsing/CircuitParser.hpp                ${OOPA_test_SOURCE_DIR}/../CircuitParsing/CircuitParser.cpp
    ${OOPA_test_SOURCE_DIR}/../CircuitUtility/StrUtil.hpp                      ${OOPA_test_SOURCE_DIR}/../CircuitUtility/StrUtil.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/NodeTypes.hpp                           ${OOPA_test_SOURCE_DIR}/../Circuit/NodeTypes.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Observed.hpp                            ${OOPA_test_SOURCE_DIR}/../Circuit/Observed.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Observer.hpp                            ${OOPA_test_SOURCE_DIR}/../Circuit/Observer.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Circuit.hpp                             ${OOPA_test_SOURCE_DIR}/../Circuit/Circuit.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/Node.hpp                          ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/Node.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/Gate.hpp                          ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/Gate.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/AndGate.hpp                       ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/AndGate.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/NotGate.hpp                       ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/NotGate.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/OrGate.hpp                        ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/OrGate.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/NorGate.hpp                       ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/NorGate.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/XorGate.hpp                       ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/XorGate.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/NandGate.hpp                      ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/NandGate.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/Input.hpp                         ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/Input.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/InputHigh.hpp                     ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/InputHigh.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/InputLow.hpp                      ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/InputLow.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/Probe.hpp                         ${OOPA_test_SOURCE_DIR}/../Circuit/Nodes/Probe.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/NodeFactory.hpp                         ${OOPA_test_SOURCE_DIR}/../Circuit/NodeFactory.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/CircuitVisitors/CircuitVisitor.hpp      ${OOPA_test_SOURCE_DIR}/../Circuit/CircuitVisitors/CircuitVisitor.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/CircuitVisitors/CircuitStatsVisitor.hpp ${OOPA_test_SOURCE_DIR}/../Circuit/CircuitVisitors/CircuitStatsVisitor.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/CircuitVisitors/UnconnectedVisitor.hpp  ${OOPA_test_SOURCE_DIR}/../Circuit/CircuitVisitors/UnconnectedVisitor.cpp
    ${OOPA_test_SOURCE_DIR}/../Circuit/CircuitVisitors/CircuitFeedbackVisitor.hpp ${OOPA_test_SOURCE_DIR}/../Circuit/CircuitVisitors/CircuitFeedbackVisitor.cpp
)

add_executable(OOPA_test ${OOPA_SRC} test_test.cpp test_AndGate.cpp mock_input.hpp mock_probe.hpp)
target_link_libraries(OOPA_test gtest gmock_main)
