#include <iostream>
#include <fstream>

#include "CircuitParsing/Stage1Lexer.hpp"
#include "CircuitParsing/Stage2Lexer.hpp"
#include "CircuitParsing/CircuitParser.hpp"
#include "CircuitParsing/InputFileNode.hpp"

using namespace std;

void writeLexemeStreamToFile(CircuitParsing::LexemeStream stream, string filename);
void writeInputFileDataToFile(CircuitParsing::InputFileData data, string filename);

int main() {
    string pwd = "/home/mafn/School/OOPatronen/Practicum/Assignment/";

    // Lex the input file
    cout << "[Stage 1 lexing ] START" << endl;
    CircuitParsing::Stage1Lexer appels(pwd + "circuit1.txt");
    cout << "[Stage 1 lexing ] END" << endl;

    cout << "[Stage 2 lexing ] START" << endl;
    CircuitParsing::Stage2Lexer peren(appels.output);
    cout << "[Stage 2 lexing ] END" << endl;

    cout << "[Stage 1 parsing] START" << endl;
    CircuitParsing::CircuitParser bananen(peren.output);
    cout << "[Stage 1 parsing] END" << endl;

    // Print the results
    writeLexemeStreamToFile(appels.output, "Stage1.txt");
    writeLexemeStreamToFile(peren.output, "Stage2.txt");
    writeInputFileDataToFile(bananen.output, "Parsing.txt");

    return 0;
}

void writeLexemeStreamToFile(CircuitParsing::LexemeStream stream, string filename) {
    string pwd = "/home/mafn/School/OOPatronen/Practicum/Assignment/";
    ofstream output(pwd + filename, ofstream::out);

    for(CircuitParsing::Lexeme lexeme : stream) {
        output << "<" << lexeme.type;
        if (!lexeme.value.empty()) {
            output << " value=" << lexeme.value;
        }
        output << ">";
        if (lexeme.type == CircuitParsing::LexemeType::SEMICOLON) {
            output << endl;
        }
    }
}

void writeInputFileDataToFile(CircuitParsing::InputFileData data, string filename) {
    string pwd = "/home/mafn/School/OOPatronen/Practicum/Assignment/";
    ofstream output(pwd + filename, ofstream::out);

    output << "Parsing results:" << endl << endl;
    output << "Nodes: " << endl;
    for(CircuitParsing::InputFileNode &node : data.nodes) {
        output << node.type << " named " << node.name << endl;
    }

    output << endl << "Edges: " << endl;
    for(map<CircuitParsing::InputFileNode*, vector<CircuitParsing::InputFileNode*>>::iterator it = data.edges.begin(); it != data.edges.end(); it++) {
        output << (*it).first->name << " has edges:" << endl;
        for(CircuitParsing::InputFileNode* edgeNode: (*it).second) {
            output << "    " << edgeNode->name << endl;
        }
        output << endl;
    }
}