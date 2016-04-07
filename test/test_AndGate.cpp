//
// Created by mafn on 4/7/16.
//

#include "gtest/gtest.h"
#include "Circuit/Nodes/AndGate.hpp"

class TestAndGate : public testing::Test {
protected:
    Circuit::AndGate* gate;

    virtual void SetUp() {
        this->gate = new Circuit::AndGate("I am AND Gate");
    }

    virtual void TearDown() {
        delete this->gate;
    }
};

TEST_F(TestAndGate, name) {
    ASSERT_EQ(this->gate->name, "I am AND Gate");
}