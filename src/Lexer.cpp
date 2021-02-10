#include "Lexer.h"

struct Keyword
{
    TokenType type;
    TFString content;
};

enum State 
{
    Success,
    Fail,
    Error
};

using FuncIdentifier = Keyword;

bool isEnd(char c)
{
    return c == '\0';
}

bool isNewLine(char c)
{
    return c == '\n';
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool isLower(char c)
{
    return c >= 'a' && c <= 'z';
}

bool isUpper(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool isValidFuncIdentifierStart(char c)
{
    return isLower(c) || isUpper(c);
}

bool isValidFuncIdentifierChar(char c)
{
    return isValidFuncIdentifierStart(c) || isDigit(c);
}

class Tokenizer
{
public:
    Tokenizer(const TFString& code);
    LexerResult tokenize();

private:
    Token nextToken();

    Token createToken(TokenType type, const TFString& lexemme, double number = 0);
    Token createToken(TokenType type);    

    void nextSymbol();
    void previousSymbol();
    void nextLine();
    bool match(char c);
    void setError(const TFString& what);
    bool filter(TokenType type);

    TFString parseComment();
    double parseNumber();
    Keyword parseKeyword();
    FuncIdentifier parseFuncIdentifier();
    int parsePlaceholder();

    template<typename T>
    const T& SUCCESS(const T& val);
    
    template<typename T>
    const T& FAIL(const T& val);
    
    template<typename T>
    const T& ERROR(const T& val);    
private:

    unsigned line;
    unsigned column;
    unsigned currentPos;
    TFString code;

    State currentState;
    TFError error;

    TFUnorderedMap<TFString, TokenType> keywordsTable;
};

Tokenizer::Tokenizer(const TFString& code):
    line(0),
    column(0),
    currentPos(0),
    code(code),
    currentState(State::Success),
    error()
{
    keywordsTable["add"] = TokenType::Add;
    keywordsTable["sub"] = TokenType::Sub;
    keywordsTable["mul"] = TokenType::Mul;
    keywordsTable["div"] = TokenType::Div;
    keywordsTable["pow"] = TokenType::Pow;
    keywordsTable["sqrt"] = TokenType::Sqrt;
    keywordsTable["sin"] = TokenType::Sin;
    keywordsTable["cos"] = TokenType::Cos;
    keywordsTable["eq"] = TokenType::Eq;
    keywordsTable["le"] = TokenType::Le;
    keywordsTable["nand"] = TokenType::Nand;
    keywordsTable["if"] = TokenType::If;
    keywordsTable["list"] = TokenType::List;
    keywordsTable["head"] = TokenType::Head;
    keywordsTable["tail"] = TokenType::Tail;
    keywordsTable["map"] = TokenType::Map;
    keywordsTable["filter"] = TokenType::Filter;
    keywordsTable["fact"] = TokenType::Factorial;
}

LexerResult tokenize(const TFString& code)
{
    Tokenizer t(code);
    return t.tokenize();
}

LexerResult Tokenizer::tokenize()
{
    LexerResult result{true};
    Token currentToken;
    do {
        currentToken = nextToken();

        if(currentState == State::Error)
        {
            result.isSuccessful = false;
            result.error = TFError(error);
            return result;
        }
        if(filter(currentToken.type))
        {
            result.tokens.push_back(currentToken);
        }
    } while(currentToken.type != TokenType::Eof && currentToken.type != TokenType::Invalid);

    return result;
}

Token Tokenizer::nextToken()
{
    if(isEnd(code[currentPos])) 
    {
        return createToken(TokenType::Eof);
    }

    TFString comment = parseComment();
    if(currentState == State::Success)
    {
        return createToken(TokenType::Comment, comment);
    }
    else if(currentState == State::Error)
    {
        return createToken(TokenType::Invalid);
    }

    switch(code[currentPos])
    {
        case '(':
            nextSymbol();
            return createToken(TokenType::LeftParen);
        case ')':
            nextSymbol();
            return createToken(TokenType::RightParen);
        case ',':
            nextSymbol();
            return createToken(TokenType::Comma);
        case '<':
            nextSymbol();
            return match('-') ? createToken(TokenType::LeftArrow): createToken(TokenType::Invalid);
        case ' ':
            nextSymbol();
            return createToken(TokenType::Whitespace);
        case '\n':
            nextLine();
            return createToken(TokenType::NewLine);
        case '\t':
            nextSymbol();
            return createToken(TokenType::Tab);
        case '#':
            return createToken(TokenType::Placeholder, "", parsePlaceholder());
        default:
            break;
    }

    bool isNegative = false;
    if(code[currentPos] == '-')
    {
        isNegative = true;
    }
    double number = parseNumber();
    if(currentState == State::Success)
    {
        //nextSymbol();
        return !isNegative? createToken(TokenType::Number, "", number): createToken(TokenType::Number, "", -number);
    }

    Keyword keyword = parseKeyword();
    if(currentState == State::Success)
    {
        return createToken(keyword.type, keyword.content);
    }
    else if(currentState == State::Error)
    {
        return createToken(TokenType::Invalid);
    }


    FuncIdentifier FuncIdentifier = parseFuncIdentifier();
    if(currentState == State::Success)
    {
        return createToken(FuncIdentifier.type, FuncIdentifier.content);
    }  
    else if(currentState == State::Error)
    {
        return createToken(TokenType::Invalid);
    }

    return createToken(TokenType::Invalid);
}

Token Tokenizer::createToken(TokenType type, const TFString& lexemme, double number)
{
    Token token = Token{type, line, column, lexemme, number};
    return token;
}

Token Tokenizer::createToken(TokenType type)
{
    switch(type)
    {
        case TokenType::LeftParen:
            return createToken(type, "(");
        case TokenType::RightParen:
            return createToken(type, ")");
        case TokenType::Comma:
            return createToken(type, ",");
        case TokenType::LeftArrow:
            return createToken(type, "<-");
        default:
            break;
    };
    return createToken(type, "");
}

void Tokenizer::nextSymbol()
{
    currentPos++;
    column++;
}

void Tokenizer::previousSymbol()
{
    currentPos--;
    column--;
}

void Tokenizer::nextLine()
{
    line++;
    currentPos++;
    column = 0;
}

bool Tokenizer::match(char c)
{
    if(c == code[currentPos])
    {
        nextSymbol();
        return true;
    }
    return false;
}

void Tokenizer::setError(const TFString& what) 
{
    error = TFError{line, column, "Error: " + what};
}

bool Tokenizer::filter(TokenType type)
{
    return !(type == TokenType::NewLine || type == TokenType::Whitespace || type == TokenType::Tab);
}

TFString Tokenizer::parseComment()
{
    unsigned start = currentPos;

    if(!match('/'))
    {
        return FAIL(TFString());
    }

    if(match('/'))
    {
        while(!isEnd(code[currentPos]) && !isNewLine(code[currentPos]))
        {
            nextSymbol();
        }
        return SUCCESS(TFString(code, start, currentPos - start));
    }
    else if(!match('*')) 
    {
        previousSymbol();
        return FAIL(TFString());
    }
    while(!isEnd(code[currentPos]))
    {
        if(match('*') && match('/'))
        {
            return SUCCESS(TFString(code, start, currentPos - start));
        }
        nextSymbol();
    }

    setError("unterminated comment");
    return ERROR(TFString());
}

double Tokenizer::parseNumber()
{
    if(!isDigit(code[currentPos]))
    {
        return FAIL(0);
    }

    size_t n = 0;

    double number = std::stod(code.c_str() + currentPos, &n);
    currentPos += static_cast<unsigned>(n);
    column += static_cast<unsigned>(n);

    return SUCCESS(number);
}

Keyword Tokenizer::parseKeyword()
{
    if(!isLower(code[currentPos]))
    {
        return FAIL(Keyword());
    }

    unsigned start = currentPos;

    while(isLower(code[currentPos]))
    {
        nextSymbol();
    }

    TFString keyword = TFString(code, start, currentPos - start);
    TFUnorderedMap<TFString, TokenType>::const_iterator it = keywordsTable.find(keyword);

    if(it == keywordsTable.end())
    {
        column -= currentPos - start;
        currentPos = start;

        return FAIL(Keyword());
    }

    return SUCCESS((Keyword{it->second, it->first}));
}

FuncIdentifier Tokenizer::parseFuncIdentifier()
{
    if(!isValidFuncIdentifierStart(code[currentPos]))
    {
        return FAIL(FuncIdentifier());
    }

    unsigned start = currentPos;

    nextSymbol();
    while(isValidFuncIdentifierChar(code[currentPos]))
    {
        nextSymbol();
    }

    return SUCCESS((FuncIdentifier{TokenType::Func, TFString(code, start, currentPos - start)}));
}

int Tokenizer::parsePlaceholder()
{
    if(!match('#'))
    {
        return FAIL(0);
    }

    int num = parseNumber();
    if(currentState == State::Fail)
    {
        return FAIL(0);
    }

    return SUCCESS(num);
}

template<typename T>
const T& Tokenizer::SUCCESS(const T& val)
{
    currentState = State::Success;
    return val;
}

template<typename T>
const T& Tokenizer::FAIL(const T& val)
{
    currentState = State::Fail;
    return val;
}

template<typename T>
const T& Tokenizer::ERROR(const T& val)
{
    currentState = State::Error;
    return val;
}  