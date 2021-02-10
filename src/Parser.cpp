#include "Parser.h"
#include "VisitorDelete.h"
#include <iostream>


bool isFunc(const Token& token)
{
    return token.type == TokenType::Func;
}

class Parser
{
public:
    Parser(const TFVector<Token>& tokens);
    FunctionExpressionPtr parse();

private:
    bool filter(TokenType type);
    bool match(TokenType type);
    void nextToken() { current++; }
    Token& prev() { return tokens[current-1]; }

    FunctionExpressionPtr createNode(TokenType type);
    FunctionExpressionPtr parseToken();

    FunctionExpressionPtr parseLiteralExpression();
    FunctionExpressionPtr parseAddFunction();
    FunctionExpressionPtr parseSubFunction();
    FunctionExpressionPtr parseMulFunction();
    FunctionExpressionPtr parseDivFunction();
    FunctionExpressionPtr parsePowFunction();
    FunctionExpressionPtr parseSqrtFunction();
    FunctionExpressionPtr parseSinFunction();
    FunctionExpressionPtr parseCosFunction();
    FunctionExpressionPtr parseLeFunction();
    FunctionExpressionPtr parseNandFunction();
    FunctionExpressionPtr parseEqFunction();
    FunctionExpressionPtr parseIfFunction();
    FunctionExpressionPtr parseListFunction(); 
    FunctionExpressionPtr parseHeadFunction();
    FunctionExpressionPtr parseTailFunction();
    FunctionExpressionPtr parseMapFunction();
    FunctionExpressionPtr parseFilterFunction();
    FunctionExpressionPtr parseFunctionDeclaration();
    FunctionExpressionPtr parseFunctionExpression();
    FunctionExpressionPtr parseFunction();
    FunctionExpressionPtr parsePlaceholder();
    FunctionExpressionPtr parseFactorial();

private:

    struct Location 
    {
        unsigned line;
        unsigned column;
    };

    Location getLocation() const { return Location{tokens[current].line, tokens[current].column}; }

private:
    TFVector<Token> tokens;
    unsigned current;
};

FunctionExpressionPtr parse(const TFVector<Token>& tokens)
{
    Parser p(tokens);
    return p.parse();
}

Parser::Parser(const TFVector<Token>& tokens):
    tokens(tokens),
    current(0)
{
}

bool Parser::filter(TokenType type)
{
    return type == TokenType::LeftParen 
        || type == TokenType::RightParen
        || type == TokenType::Comma;
}

bool Parser::match(TokenType type)
{
    if(tokens[current].type == type)
    {
        current++;
        return true;
    }
    return false;
}

FunctionExpressionPtr Parser::parseLiteralExpression()
{
    Location location = getLocation();
    if(match(TokenType::Number))
    {
        LiteralNumber* num = new LiteralNumber(prev().number);
        num->setLocation(location.line, location.column);
        return num;
    }
    return nullptr;
}

FunctionExpressionPtr Parser::parse()
{
    while(filter(tokens[current].type) && current <= tokens.size())
    {
        nextToken();
    }

    switch (tokens[current].type)
    {        
        case TokenType::Number:
            return parseLiteralExpression();
        case TokenType::Add: 
            nextToken();
            return parseAddFunction();
        case TokenType::Sub: 
            nextToken();
            return parseSubFunction();
        case TokenType::Mul: 
            nextToken();
            return parseMulFunction();
        case TokenType::Div: 
            nextToken();
            return parseDivFunction();
        case TokenType::Pow: 
            nextToken();
            return parsePowFunction();
        case TokenType::Sqrt: 
            nextToken();
            return parseSqrtFunction();
        case TokenType::Sin:    
            nextToken();
            return parseSinFunction();
        case TokenType::Cos: 
            nextToken();
            return parseCosFunction();
        case TokenType::Eq: 
            nextToken();
            return parseEqFunction();
        case TokenType::Le: 
            nextToken();
            return parseLeFunction();
        case TokenType::Nand: 
            nextToken();
            return parseNandFunction();
        case TokenType::If: 
            nextToken();
            return parseIfFunction();
        case TokenType::List: 
            nextToken();
            return parseListFunction();
        case TokenType::Head: 
            nextToken();
            return parseHeadFunction();
        case TokenType::Tail: 
            nextToken();
            return parseTailFunction();
        case TokenType::Map: 
            nextToken();
            return parseMapFunction();
        case TokenType::Filter:
            nextToken(); 
            return parseFilterFunction();
        case TokenType::Func:
            nextToken();
            return parseFunction();
        case TokenType::Placeholder:
            return parsePlaceholder();
        case TokenType::Factorial:
            nextToken();
            return parseFactorial();
    }
    return nullptr;
}

FunctionExpressionPtr Parser::parseAddFunction()
{
    Location location = getLocation();

    AddFunction* result = new AddFunction;
    result->setLocation(location.line, location. column);
    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->left = parse();
    nextToken();
    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->right = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseSubFunction()
{
    Location location = getLocation();

    SubFunction* result = new SubFunction;
    result->setLocation(location.line, location. column);
    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->left = parse();
    nextToken();
    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->right = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseMulFunction()
{
    Location location = getLocation();

    MulFunction* result = new MulFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->left = parse();

    nextToken();
    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->right = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseDivFunction()
{
    Location location = getLocation();

    DivFunction* result = new DivFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->left = parse();

    nextToken();
    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->right = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parsePowFunction()
{
    Location location = getLocation();

    PowFunction* result = new PowFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->base = parse();

    nextToken();
    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->exponent = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseSqrtFunction()
{
    Location location = getLocation();

    SqrtFunction* result = new SqrtFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->arg = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseSinFunction()
{
    Location location = getLocation();

    SinFunction* result = new SinFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->arg = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseFactorial()
{

    Location location = getLocation();

    FactorialFunction* result = new FactorialFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->arg = parse();

    nextToken();

    return result;
}

FunctionExpressionPtr Parser::parseCosFunction()
{
    Location location = getLocation();

    CosFunction* result = new CosFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->arg = parse();
    nextToken();    
    return result;
}

FunctionExpressionPtr Parser::parseLeFunction()
{
    Location location = getLocation();

    LeFunction* result = new LeFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->left = parse();

    nextToken();
    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->right = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseNandFunction()
{
    Location location = getLocation();

    NandFunction* result = new NandFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->left = parse();

    nextToken();
    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->right = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseEqFunction()
{
    Location location = getLocation();

    EqFunction* result = new EqFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->left = parse();

    nextToken();
    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->right = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseIfFunction()
{
    Location location = getLocation();

    IfFunction* result = new IfFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->condition = parse();

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->ifStatement = parse();

    while(filter(tokens[current].type) && current <= tokens.size())
    {
        nextToken();
    }
    result->elseStatement = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseListFunction()
{
    Location location = getLocation();

    ListFunction* result = new ListFunction;
    result->setLocation(location.line, location. column);

    nextToken();
    while(tokens[current].type != TokenType::RightParen)
    {
        result->values.push_back(parse());
        if(tokens[current].type != TokenType::RightParen)
            nextToken();
    }

    nextToken();

    return result;
}

FunctionExpressionPtr Parser::parseHeadFunction()
{
    Location location = getLocation();

    HeadFunction* result = new HeadFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->val = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseTailFunction()
{
    Location location = getLocation();

    TailFunction* result = new TailFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    result->values = parse();
    
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseMapFunction()
{
    Location location = getLocation();

    MapFunction* result = new MapFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }
    
    result->functionName = tokens[current].lexeme;
    nextToken();
    nextToken();
    result->values = parse();
    
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseFilterFunction()
{
    Location location = getLocation();

    MapFunction* result = new MapFunction;
    result->setLocation(location.line, location. column);

    while(filter(tokens[current].type))
    {
        nextToken();
    }

    result->functionName = tokens[current].lexeme;
    nextToken();
    nextToken();
    result->values = parse();
    
    nextToken();  
    return result;
}

FunctionExpressionPtr Parser::parseFunctionDeclaration()
{
    Location location = getLocation();

    FunctionDeclaration* result = new FunctionDeclaration;
    result->setLocation(location.line, location. column);
    
    result->name = prev().lexeme;
    nextToken();

    result->body = parse();
    nextToken();
    return result;
}

FunctionExpressionPtr Parser::parseFunctionExpression()
{
    Location location = getLocation();

    FunctionCall* result = new FunctionCall;
    result->setLocation(location.line, location. column);
    
    result->name = prev().lexeme;
    nextToken();
    
    while(tokens[current].type != TokenType::RightParen)
    {
        FunctionExpressionPtr temp = parse();
        if(!temp)
        {
            VisitorDelete v;
            result->accept(v);
            return nullptr;
        }
        result->args.push_back(parse());

        if(tokens[current].type == TokenType::Comma)
            nextToken();
    }
    nextToken();

    return result;
}

FunctionExpressionPtr Parser::parseFunction()
{
    if(tokens[current].type == TokenType::LeftArrow)
    {
        return parseFunctionDeclaration();
    }
    return parseFunctionExpression();
}

FunctionExpressionPtr Parser::parsePlaceholder()
{    
    Location location = getLocation();

    PlaceholderDeclaration* result = new PlaceholderDeclaration;
    result->setLocation(location.line, location. column);
    
    result->index = tokens[current].number;
    nextToken();

    return result;
}