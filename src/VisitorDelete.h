#ifndef _VISITOR_DELETE_HEADER
#define _VISITOR_DELETE_HEADER

#include "Declarations.h"
#include "Visitor.h"
#include "FunctionExpression.h"

class VisitorDelete: public Visitor
{
public:
    virtual ~VisitorDelete() {}

    virtual void visit(LiteralNumber* f) override;
    virtual void visit(AddFunction* f) override ;
    virtual void visit(SubFunction* f) override ;
    virtual void visit(MulFunction* f) override ;
    virtual void visit(DivFunction* f) override ;
    virtual void visit(PowFunction* f) override;
    virtual void visit(SqrtFunction* f) override;
    virtual void visit(SinFunction* f) override;
    virtual void visit(CosFunction* f) override;
    virtual void visit(LeFunction* f) override;
    virtual void visit(NandFunction* f) override;
    virtual void visit(EqFunction* f) override;
    virtual void visit(IfFunction* f) override;
    virtual void visit(ListFunction* f) override;
    virtual void visit(HeadFunction* f) override; 
    virtual void visit(TailFunction* f) override;
    virtual void visit(MapFunction* f) override;
    virtual void visit(FilterFunction* f) override;
    virtual void visit(FunctionDeclaration* f) override;
    virtual void visit(PlaceholderDeclaration* f) override;
    virtual void visit(FunctionCall* f) override;
    virtual void visit(FactorialFunction* f) override;
};

#endif