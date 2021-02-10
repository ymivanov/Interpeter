#ifndef _VISITOR_HEADER
#define _VISITOR_HEADER

#include "Declarations.h"

class Visitor
{
public:
    virtual ~Visitor() {}

    virtual void visit(LiteralNumber* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(AddFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(SubFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(MulFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(DivFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(PowFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(SqrtFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(SinFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(CosFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(LeFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(NandFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(EqFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(IfFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(ListFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(HeadFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(TailFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(MapFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(FilterFunction* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(FunctionDeclaration* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(PlaceholderDeclaration* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(FunctionCall* f) { (void)f; NOT_IMPLEMENTED; }
    virtual void visit(FactorialFunction* f) { (void)f; NOT_IMPLEMENTED; }
};

#endif