//
// Created by mafn on 4/7/16.
//

#ifndef OOPA_CIRCUITSIM_MOCK_INPUT_HPP
#define OOPA_CIRCUITSIM_MOCK_INPUT_HPP

#endif //OOPA_CIRCUITSIM_MOCK_INPUT_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Circuit/Nodes/Input.hpp"
#include "Circuit/Nodes/Node.hpp"

class MockInput : public Circuit::Input {
public:
    MockInput(): Input("MOCKED Input"){};

    MOCK_METHOD0(canEvaluate, bool());
    MOCK_METHOD0(evaluateOutput, bool());
    MOCK_METHOD0(update, void());
    MOCK_METHOD0(evaluate, void());
    MOCK_METHOD1(addInput, void(Circuit::Node* toAdd));
    MOCK_METHOD1(addEdge, void(Circuit::Node* toAdd));
};