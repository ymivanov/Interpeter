#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Lexer.h"
#include "../Parser.h"
#include "../ASTInterpreter.h"
#include "../VisitorDelete.h"

TEST_CASE("Lexer add function") 
{
    LexerResult res = tokenize("add(1, 2)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Add, 0, 0, "add", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 2});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}

TEST_CASE("Lexer sub function") 
{
    LexerResult res = tokenize("sub(1, 2)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Sub, 0, 0, "sub", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 2});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}

TEST_CASE("Lexer mul function") 
{
    LexerResult res = tokenize("mul(1, 2)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Mul, 0, 0, "mul", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 2});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}

TEST_CASE("Lexer div function") 
{
    LexerResult res = tokenize("div(2, 3)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Div, 0, 0, "div", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 2});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 3});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}

TEST_CASE("Lexer pow function") 
{
    LexerResult res = tokenize("pow(2, 3)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Pow, 0, 0, "pow", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 2});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 3});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}

TEST_CASE("Lexer sqrt function") 
{
    LexerResult res = tokenize("sqrt(4)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Sqrt, 0, 0, "sqrt", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 4});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}

TEST_CASE("Lexer sin function") 
{
    LexerResult res = tokenize("sin(1)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Sin, 0, 0, "sin", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}

TEST_CASE("Lexer cos function") 
{
    LexerResult res = tokenize("cos(1)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Cos, 0, 0, "cos", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}


TEST_CASE("Lexer le function") 
{
    LexerResult res = tokenize("le(1, 5)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Le, 0, 0, "le", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 5});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}

TEST_CASE("Lexer nand function") 
{
    LexerResult res = tokenize("nand(0, 1)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Nand, 0, 0, "nand", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 0});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}


TEST_CASE("Lexer eq function") 
{
    LexerResult res = tokenize("eq(0, 1)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Eq, 0, 0, "eq", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 0});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}


TEST_CASE("Lexer if function") 
{
    LexerResult res = tokenize("if(add(1, 0), 1, 2)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::If, 0, 0, "if", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Add, 0, 0, "add", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 0});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 2});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}


TEST_CASE("Lexer list function") 
{
    LexerResult res = tokenize("list(0, 1, sqrt(4))");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::List, 0, 0, "list", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 0});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Sqrt, 0, 0, "sqrt", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 4});    
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}


TEST_CASE("Lexer head function") 
{
    LexerResult res = tokenize("head(0, 1, sqrt(4))");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Head, 0, 0, "head", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 0});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Sqrt, 0, 0, "sqrt", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 4});    
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}

TEST_CASE("Lexer tail function") 
{
    LexerResult res = tokenize("tail(0, 1, sqrt(4))");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Tail, 0, 0, "tail", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 0});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Sqrt, 0, 0, "sqrt", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 4});    
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}

TEST_CASE("Lexer map function") 
{
    LexerResult res = tokenize("map(f, list(1, 2, 3))");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Map, 0, 0, "map", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Func, 0, 0, "f", 0.0});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::List, 0, 0, "list", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 2});  
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 3});    
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}


TEST_CASE("Lexer filter function") 
{
    LexerResult res = tokenize("filter(f, list(1, 2, 3))");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Filter, 0, 0, "filter", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Func, 0, 0, "f", 0.0});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::List, 0, 0, "list", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 2});  
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 3});    
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}

TEST_CASE("Lexer function declaration") 
{
    LexerResult res = tokenize("f <- pow(#0, #1)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Func, 0, 0, "f", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftArrow, 0, 0, "<-", 0.0});
    expected.tokens.push_back(Token{TokenType::Pow, 0, 0, "pow", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Placeholder, 0, 0, "", 0});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Placeholder, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}

TEST_CASE("Lexer function call") 
{
    LexerResult res = tokenize("myFunc(1, 2)");
    LexerResult expected;
    expected.tokens.push_back(Token{TokenType::Func, 0, 0, "myFunc", 0.0});
    expected.tokens.push_back(Token{TokenType::LeftParen, 0, 0, "(", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 1});
    expected.tokens.push_back(Token{TokenType::Comma, 0, 0, ",", 0.0});
    expected.tokens.push_back(Token{TokenType::Number, 0, 0, "", 2});
    expected.tokens.push_back(Token{TokenType::RightParen, 0, 0, ")", 0.0});
    expected.tokens.push_back(Token{TokenType::Eof, 0, 0, "", 0.0});

    for(int i = 0; i < res.tokens.size(); i++)
    {
        CHECK(res.tokens[i].type == expected.tokens[i].type);
        CHECK(res.tokens[i].lexeme == expected.tokens[i].lexeme);
        CHECK(res.tokens[i].number == expected.tokens[i].number);
    }
}


TEST_CASE("Parse and evaluate: Add function evaluation")
{
    LexerResult result = tokenize("add(1, 2");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 3);
}


TEST_CASE("Parse and evaluate: Add function evaluation(nested)")
{
    LexerResult result = tokenize("add(add(1, 2), add(5, 6))");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 14);
}

TEST_CASE("Parse and evaluate: Sub function evaluation")
{
    LexerResult result = tokenize("sub(1, 2)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == -1);
}

TEST_CASE("Parse and evaluate: Sub function evaluation(nested)")
{
    LexerResult result = tokenize("sub(sub(15, 6), sub(5, 3))");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 7);
}

TEST_CASE("Parse and evaluate: Mul function evaluation")
{
    LexerResult result = tokenize("mul(10, 2)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 20);
}

TEST_CASE("Parse and evaluate: Mul function evaluation(nested)")
{
    LexerResult result = tokenize("mul(mul(1, 3), mul(2, 3))");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 18);
}


TEST_CASE("Parse and evaluate: Div function evaluation")
{
    LexerResult result = tokenize("div(10, 2)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 5);
}

TEST_CASE("Parse and evaluate: Div function evaluation(nested)")
{
    LexerResult result = tokenize("div(mul(5, 2), 5)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 2);
}


TEST_CASE("Parse and evaluate: Pow function evaluation")
{
    LexerResult result = tokenize("pow(2, 3)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 8);
}

TEST_CASE("Parse and evaluate: Pow function evaluation(nested)")
{
    LexerResult result = tokenize("pow(mul(5, 2), 2)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 100);
}

TEST_CASE("Parse and evaluate: Sqrt function evaluation")
{
    LexerResult result = tokenize("sqrt(144)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 12);
}

TEST_CASE("Parse and evaluate: Sqrt function evaluation(nested)")
{
    LexerResult result = tokenize("sqrt(mul(10, 10))");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 10);
}

TEST_CASE("Parse and evaluate: Sin function evaluation")
{
    LexerResult result = tokenize("sin(0)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 0);
}

TEST_CASE("Parse and evaluate: Sin function evaluation(nested)")
{
    LexerResult result = tokenize("sin(mul(0, 10))");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 0);
}


TEST_CASE("Parse and evaluate: Cos function evaluation")
{
    LexerResult result = tokenize("cos(0)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 1);
}

TEST_CASE("Parse and evaluate: Cos function evaluation(nested)")
{
    LexerResult result = tokenize("cos(add(0, mul(0, 1)))");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 1);
}

TEST_CASE("Parse and evaluate: Le function evaluation")
{
    LexerResult result = tokenize("le(0, 5)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 1);
}

TEST_CASE("Parse and evaluate: Le function evaluation(nested)")
{
    LexerResult result = tokenize("le(add(0, mul(0, 1)), sub(10, 5))");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 1);
}

TEST_CASE("Parse and evaluate: Nand function evaluation")
{
    LexerResult result = tokenize("nand(0, 1)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 1);
}

TEST_CASE("Parse and evaluate: Le function evaluation(nested)")
{
    LexerResult result = tokenize("nand(add(0, mul(0, 1)), sub(10, 9))");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 1);
}


TEST_CASE("Parse and evaluate: Eq function evaluation")
{
    LexerResult result = tokenize("eq(0, 1)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 0);
}

TEST_CASE("Parse and evaluate: Eq function evaluation(nested)")
{
    LexerResult result = tokenize("eq(add(0, mul(10, 3)), sub(39, 9))");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 1);
}

TEST_CASE("Parse and evaluate: If function evaluation")
{
    LexerResult result = tokenize("if(0, add(1, 2), mul(3, 4))");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 12);
}

TEST_CASE("Parse and evaluate: If function evaluation(nested)")
{
    LexerResult result = tokenize("if(add(0, mul(10, 3)), sub(39, 9), 10)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 30);
}

TEST_CASE("Parse and evaluate: List function evaluation")
{
    LexerResult result = tokenize("list(1, 2, 3, 4)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 1);
}

TEST_CASE("Parse and evaluate: List function evaluation(nested)")
{
    LexerResult result = tokenize("list(add(0, mul(10, 3)), sub(39, 9), 10)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 30);
}

TEST_CASE("Parse and evaluate: Head function evaluation")
{
    LexerResult result = tokenize("head(1, 2, 3, 4)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 1);
}

TEST_CASE("Parse and evaluate: Head function evaluation(nested)")
{
    LexerResult result = tokenize("head(add(0, mul(10, 3)), sub(39, 9), 10)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 30);
}

TEST_CASE("Parse and evaluate: Map function evaluation")
{
    LexerResult result = tokenize("f <- sqrt(#0)");
    FunctionExpressionPtr root = parse(result.tokens);
    ASTInterpreter interpreter;
    interpreter.run(root);

    result = tokenize("map(f, list(4, 16, 64)");
    root = parse(result.tokens);
    interpreter.run(root);

    VisitorDelete v;
    root->accept(v);
    CHECK(interpreter.getResult() == 2);
}