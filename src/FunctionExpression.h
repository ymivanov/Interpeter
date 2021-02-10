#ifndef _FUNCTION_HEADER
#define _FUNCTION_HEADER

#include "Declarations.h"
#include "Visitor.h"
#include "FunctionDefinitions.h"

class FunctionExpression
{
public:
    FunctionExpression() {}
    virtual ~FunctionExpression() {}
    virtual void accept(Visitor& v) = 0;
    unsigned getLine() const { return line; }
    unsigned getColumn() const { return column; }
    void setLocation(unsigned l, unsigned c) { line = l; column = c; }
private:
    unsigned line;
    unsigned column;
};

#define EXPAND_ARGUMENT(type, name, def)\
                const type& name = def,

#define EXPAND_INITIALIZER_LIST(type, name, def)\
                name(name),

#define GENERATE_GETTERS(type, name, def)\
                const type& get##name() const { return name; }\
                type& get##name##ByRef() { return name; }

#define GENERATE_MEMBER_DEFINITIONS(type, name, def)\
                type name;

#define GENERATE_FUNCTION_EXPRESSION(ClassName, MEMBERS_ITERATOR)               \
            class ClassName : public FunctionExpression                         \
            {                                                                   \
            	public:                                                         \
            	ClassName(MEMBERS_ITERATOR(EXPAND_ARGUMENT) bool dummy = 0)     \
            	:                                                               \
            	MEMBERS_ITERATOR(EXPAND_INITIALIZER_LIST) dummy(dummy)          \
            	{                                                               \
            	}                                                               \
            	virtual ~ClassName() {}                                         \
            	virtual void accept(Visitor& v) override { v.visit(this); }     \
                                                                                \
            	MEMBERS_ITERATOR(GENERATE_GETTERS)                              \
            	MEMBERS_ITERATOR(GENERATE_MEMBER_DEFINITIONS)                   \
            	private:                                                        \
            	bool dummy;                                                     \
            };

FUNCTION_EXPRESSION_DEFINITION_ITERATOR(GENERATE_FUNCTION_EXPRESSION);
#undef GENERATE_FUNCTION_EXPRESSION

#endif