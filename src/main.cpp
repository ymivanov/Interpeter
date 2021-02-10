#include <iostream>
#include <fstream>
#include <string>
#include "Lexer.h"
#include "Parser.h"
#include "ASTInterpreter.h"
#include "VisitorDelete.h"
#include "tests/doctest.h"

void interpret(std::istream& in, bool repl)
{
    std::string currentLine;
    LexerResult result;
    FunctionExpressionPtr root;
    ASTInterpreter interpreter;
    VisitorDelete v;

    do
    {

        std::getline(in, currentLine);
        result = tokenize(currentLine);
        root = parse(result.tokens);

        if(!root)
        {
            continue;
        }
        interpreter.run(root);

        if(repl)
        {
            interpreter.printResults();
            std::cout << std::endl;
            std::cout << ">>";
        }

        root->accept(v);

    } while (currentLine != "end");

    if(!repl)
    {
        interpreter.printResults();
    }
}
/*
int main(int argc, char** argv) 
{
    bool repl;
    std::cout << "REPL?" << std::endl;
    std::cin >> repl;

    if(repl)
    {
        interpret(std::cin, repl);
    }
    else
    {
        std::string fileName;
        std::cout << "Name of file: ";
        std::cin >> fileName;
        std::ifstream in(fileName);
        interpret(in, repl);
    }

    return 0;
}*/