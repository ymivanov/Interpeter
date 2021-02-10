#ifndef _FUNCTION_DEFINITIONS
#define _FUNCTION_DEFINITIONS

#define LITERAL_NUMBER_MEMBERS(MACRO)\
                MACRO(double, val, 0.0)

#define ADD_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, left, nullptr)\
                MACRO(FunctionExpressionPtr, right, nullptr)\

#define SUB_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, left, nullptr)\
                MACRO(FunctionExpressionPtr, right, nullptr)\

#define MUL_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, left, nullptr)\
                MACRO(FunctionExpressionPtr, right, nullptr)\

#define DIV_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, left, nullptr)\
                MACRO(FunctionExpressionPtr, right, nullptr)\

#define POW_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, base, nullptr)\
                MACRO(FunctionExpressionPtr, exponent, nullptr)\

#define SQRT_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, arg, nullptr)\

#define SIN_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, arg, nullptr)

#define COS_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, arg, nullptr)

#define LE_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, left, nullptr)\
                MACRO(FunctionExpressionPtr, right, nullptr)

#define NAND_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, left, nullptr)\
                MACRO(FunctionExpressionPtr, right, nullptr)

#define EQ_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, left, nullptr)\
                MACRO(FunctionExpressionPtr, right, nullptr)

#define IF_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, condition, nullptr)\
                MACRO(FunctionExpressionPtr, ifStatement, nullptr)\
                MACRO(FunctionExpressionPtr, elseStatement, nullptr)

#define LIST_FUNCTION_MEMBERS(MACRO)\
                MACRO(TFVector<FunctionExpressionPtr>, values, TFVector<FunctionExpressionPtr>())

#define HEAD_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, val, FunctionExpressionPtr())

#define TAIL_FUNCTION_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, values, FunctionExpressionPtr())

#define MAP_FUNCTION_MEMBERS(MACRO)\
                MACRO(TFString, functionName, TFString())\
                MACRO(FunctionExpressionPtr, values, FunctionExpressionPtr())
    
#define FILTER_FUNCTION_MEMBERS(MACRO)\
                MACRO(TFString, functionName, TFString())\
                MACRO(FunctionExpressionPtr, values, FunctionExpressionPtr())

#define FUNCTION_DECLARATION_MEMBERS(MACRO)\
                MACRO(TFString, name, TFString())\
                MACRO(FunctionExpressionPtr, body, FunctionExpressionPtr())

#define FUNCTION_CALL_MEMBERS(MACRO)\
                MACRO(TFString, name, TFString())\
                MACRO(TFVector<FunctionExpressionPtr>, args, TFVector<FunctionExpressionPtr>())

#define PLACEHOLDER_MEMBERS(MACRO)\
                MACRO(unsigned, index, 0)

#define FACTORIAL_MEMBERS(MACRO)\
                MACRO(FunctionExpressionPtr, arg, nullptr)

#define FUNCTION_EXPRESSION_DEFINITION_ITERATOR(MACRO)\
                MACRO(LiteralNumber, LITERAL_NUMBER_MEMBERS)\
                MACRO(AddFunction, ADD_FUNCTION_MEMBERS)\
                MACRO(SubFunction, SUB_FUNCTION_MEMBERS)\
                MACRO(MulFunction, MUL_FUNCTION_MEMBERS)\
                MACRO(DivFunction, DIV_FUNCTION_MEMBERS)\
                MACRO(PowFunction, POW_FUNCTION_MEMBERS)\
                MACRO(SqrtFunction, SQRT_FUNCTION_MEMBERS)\
                MACRO(SinFunction, SIN_FUNCTION_MEMBERS)\
                MACRO(CosFunction, COS_FUNCTION_MEMBERS)\
                MACRO(LeFunction, LE_FUNCTION_MEMBERS)\
                MACRO(NandFunction, NAND_FUNCTION_MEMBERS)\
                MACRO(EqFunction, EQ_FUNCTION_MEMBERS)\
                MACRO(IfFunction, IF_FUNCTION_MEMBERS)\
                MACRO(ListFunction, LIST_FUNCTION_MEMBERS)\
                MACRO(HeadFunction, HEAD_FUNCTION_MEMBERS)\
                MACRO(TailFunction, TAIL_FUNCTION_MEMBERS)\
                MACRO(MapFunction, MAP_FUNCTION_MEMBERS)\
                MACRO(FilterFunction, FILTER_FUNCTION_MEMBERS)\
                MACRO(FunctionDeclaration, FUNCTION_DECLARATION_MEMBERS)\
                MACRO(PlaceholderDeclaration, PLACEHOLDER_MEMBERS)\
                MACRO(FunctionCall, FUNCTION_CALL_MEMBERS)\
                MACRO(FactorialFunction, FACTORIAL_MEMBERS)
#endif