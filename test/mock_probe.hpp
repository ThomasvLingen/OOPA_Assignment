//
// Created by mafn on 4/7/16.
//

#ifndef OOPA_CIRCUITSIM_MOCK_PROBE_HPP
#define OOPA_CIRCUITSIM_MOCK_PROBE_HPP

#endif //OOPA_CIRCUITSIM_MOCK_PROBE_HPP

#include "gmock/gmock.h"
#include "Circuit/Nodes/Probe.hpp"

class MockProbe : public Circuit::Probe {
public:
    MockProbe(): Probe("MOCKED Probe"){};

    MOCK_METHOD0(canEvaluate, bool());
    MOCK_METHOD0(evaluateOutput, bool());
    MOCK_METHOD0(update, void());
    MOCK_METHOD0(evaluate, void());
    MOCK_METHOD1(addInput, void(Circuit::Node* toAdd));
    MOCK_METHOD1(addEdge, void(Circuit::Node* toAdd));
};