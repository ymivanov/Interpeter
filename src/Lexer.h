#ifndef _LEXER_HEADER
#define _LEXER_HEADER

#include "CommonTypes.h"

enum TokenType 
{
    
// Single-char tokens
    LeftParen,
    RightParen,
    Comma,
    Placeholder,    

//Two-char tokens
    LeftArrow, 

    Number,

//Keywords
    Add,
    Sub,
    Mul,
    Div,
    Pow,
    Sqrt,
    Sin,
    Cos,
    Eq,
    Le,
    Nand,
    If,
    List,
    Head,
    Tail,
    Map,
    Filter,
    Factorial,

    Func,

    Comment,
    Whitespace,
    NewLine,
    Tab,

    Eof,
    Invalid
};

struct Token 
{
    TokenType type;
    unsigned line;
    unsigned column;
    TFString lexeme;
    double number;
};

struct LexerResult
{
	bool isSuccessful;
	TFError error;
	TFVector<Token> tokens;
};

LexerResult tokenize(const TFString& code); 

#endif