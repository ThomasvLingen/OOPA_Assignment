#include <iostream>
#include "CircuitParsing/Stage1Lexer.hpp"
#include "CircuitParsing/Stage2Lexer.hpp"
#include "CircuitParsing/CircuitParser.hpp"
#include "CircuitParsing/InputFileNode.hpp"
#include "Circuit/Observed.hpp"
#include "Circuit/Observer.hpp"
#include "FactoryTest/GateFactory.hpp"
#include "FactoryTest/AndGate.hpp"
#include "FactoryTest/OrGate.hpp"

using namespace std;

class testObserved : public Circuit::Observed {
public:
    testObserved(){};
    ~testObserved(){};
    void yoink(){
        this->notifyObservers();
    };
};

class testObserver : public Circuit::Observer {
public:
    testObserver(){};
    ~testObserver(){};
    virtual void update() {
        cout << "yoink from observer" << endl;
    }
};

int main() {
    // Lex the input file
    cout << "[Stage 1 lexing ] START" << endl;
    CircuitParsing::Stage1Lexer appels("/home/mafn/School/OOPatronen/Practicum/Assignment/circuit1.txt");
    cout << "[Stage 1 lexing ] END" << endl;

    cout << "[Stage 2 lexing ] START" << endl;
    CircuitParsing::Stage2Lexer peren(appels.output);
    cout << "[Stage 2 lexing ] END" << endl;

    cout << "[Stage 1 parsing] START" << endl;
    CircuitParsing::CircuitParser bananen(peren.output);
    cout << "[Stage 1 parsing] END" << endl;

    testObserved yoinker;
    testObserver obs;

    obs.observe(yoinker);

    yoinker.yoink();

    FactoryTest::Gate* gate = FactoryTest::GateFactory::create("AND");
    FactoryTest::Gate* gate2 = FactoryTest::GateFactory::create("OR");

    cout << gate->type << endl;
    cout << gate2->type << endl;

    return 0;
}