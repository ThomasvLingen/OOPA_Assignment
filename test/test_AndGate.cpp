//
// Created by mafn on 4/7/16.
//

#include "gtest/gtest.h"
#include "Circuit/Nodes/AndGate.hpp"
#include "Circuit/Nodes/Input.hpp"
#include "Circuit/Nodes/Probe.hpp"
#include "mock_input.hpp"
#include "mock_probe.hpp"

class TestAndGate : public testing::Test {
protected:
    Circuit::AndGate* gate;
    Circuit::Input* a;
    Circuit::Input* b;
    MockProbe* output;

    virtual void SetUp() {
        this->gate = new Circuit::AndGate("I am AND Gate");

        this->a = new MockInput();
        this->b = new MockInput();
        this->output = new MockProbe();
    }

    virtual void TearDown() {
        delete this->gate;

        delete this->a;
        delete this->b;
        delete this->output;
    }

    void attachProbe() {
        this->gate->addEdge((Circuit::Probe*)this->output);
    }

    void setGateInputs(bool a, bool b) {
        this->setInputsEvaluated(true, true);
        this->setInputsOutputs(a, b);
        this->addInputs();
    }

    void addInputs() {
        this->gate->addInput(this->a);
        this->gate->addInput(this->b);
    }

    void setInputsEvaluated(bool a, bool b) {
        this->a->evaluated = a;
        this->b->evaluated = b;
    }

    void setInputsOutputs(bool a, bool b) {
        this->a->output = a;
        this->b->output = b;
    }
};

// DEFAULTS
TEST_F(TestAndGate, defaults) {
    ASSERT_EQ(this->gate->name,      "I am AND Gate");
    ASSERT_EQ(this->gate->evaluated, false);
    ASSERT_EQ(this->gate->output,    false);
}

// CAN_EVALUATE
/* This tests if canEvaluate returns false when the gate has no inputs */
TEST_F(TestAndGate, can_evaluate_no_inputs) {
    ASSERT_EQ(this->gate->canEvaluate(), false);
}

/* This tests if canEvaluate returns false when one or more inputs is not evaluated */
TEST_F(TestAndGate, can_evaluate_inputs_not_evaluated) {
    this->addInputs();

    this->setInputsEvaluated(false, false);
    ASSERT_EQ(this->gate->canEvaluate(), false);

    this->setInputsEvaluated(true, false);
    ASSERT_EQ(this->gate->canEvaluate(), false);

    this->setInputsEvaluated(false, true);
    ASSERT_EQ(this->gate->canEvaluate(), false);
}

/* This tests is canEvaluate returns true when all inputs are invaluated */
TEST_F(TestAndGate, can_evaluate_inputs_evaluated) {
    this->addInputs();
    this->setInputsEvaluated(true, true);

    ASSERT_EQ(this->gate->canEvaluate(), true);
}

// EVALUATE
/* This tests if the gate doesn't evaluate when it cannot evaluate */
TEST_F(TestAndGate, cannot_evaluate) {
    this->attachProbe();
    EXPECT_CALL(*this->output, update()).Times(0);

    // No inputs are hooked up, so it can't evaluate
    this->gate->evaluate();

    ASSERT_EQ(this->gate->evaluated, false);
    ASSERT_EQ(this->gate->output, false);
}

/* This tests if the gate evaluates */
TEST_F(TestAndGate, can_evaluate) {
    this->attachProbe();
    this->setGateInputs(1, 1);
    EXPECT_CALL(*this->output, update()).Times(1);

    this->gate->evaluate();
}

// EVALUATE_OUTPUT
TEST_F(TestAndGate, input_0_0) {
    this->setGateInputs(0, 0);

    this->gate->evaluate();

    ASSERT_EQ(this->gate->evaluated, true);
    ASSERT_EQ(this->gate->output, false);
}

TEST_F(TestAndGate, input_0_1) {
    this->setGateInputs(0, 1);

    this->gate->evaluate();

    ASSERT_EQ(this->gate->evaluated, true);
    ASSERT_EQ(this->gate->output, false);
}

TEST_F(TestAndGate, input_1_0) {
    this->setGateInputs(1, 0);

    this->gate->evaluate();

    ASSERT_EQ(this->gate->evaluated, true);
    ASSERT_EQ(this->gate->output, false);
}

TEST_F(TestAndGate, input_1_1) {
    this->setGateInputs(1, 1);

    this->gate->evaluate();

    ASSERT_EQ(this->gate->evaluated, true);
    ASSERT_EQ(this->gate->output, true);
}