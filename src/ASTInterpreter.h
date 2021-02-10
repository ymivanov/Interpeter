#ifndef _ASTINTERPRETER_HEADER
#define _ASTINTERPRETER_HEADER

#include "Visitor.h"

class ASTInterpreter: public Visitor
{
public:
    ~ASTInterpreter();

    void run(FunctionExpressionPtr expression);
    void printResults() const;
    double getResult() const;
private:
    virtual void visit(LiteralNumber* f) override;  
    virtual void visit(AddFunction* f) override; 
    virtual void visit(SubFunction* f) override; 
    virtual void visit(MulFunction* f) override; 
    virtual void visit(DivFunction* f) override; 
    virtual void visit(PowFunction* f) override; 
    virtual void visit(ListFunction* f) override; 
    virtual void visit(SqrtFunction* f) override; 
    virtual void visit(SinFunction* f) override; 
    virtual void visit(CosFunction* f) override; 
    virtual void visit(LeFunction* f) override; 
    virtual void visit(NandFunction* f) override; 
    virtual void visit(EqFunction* f) override; 
    virtual void visit(IfFunction* f) override; 
    virtual void visit(HeadFunction* f) override; 
    virtual void visit(TailFunction* f) override; 
    virtual void visit(MapFunction* f) override; 
    virtual void visit(FilterFunction* f) override; 
    virtual void visit(FunctionDeclaration* f) override; 
    virtual void visit(FunctionCall* f) override; 
    virtual void visit(PlaceholderDeclaration* f) override;
    virtual void visit(FactorialFunction* f) override;
    
private:
    void deleteTree(FunctionExpressionPtr root);

    void setError(unsigned line, unsigned column, const TFString& what);
    
    TFUnorderedMap<TFString, FunctionExpressionPtr> funcs;
    TFVector<double> helper;
    TFVector<double> results;

    TFError error;
};

#endif