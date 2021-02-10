#ifndef _PARSER_HEADER
#define _PARSER_HEADER

#include "FunctionExpression.h"
#include "CommonTypes.h"
#include "Lexer.h"

FunctionExpressionPtr parse(const TFVector<Token>& tokens);

#endif