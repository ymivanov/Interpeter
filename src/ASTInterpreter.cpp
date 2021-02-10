#include "ASTInterpreter.h"
#include "FunctionExpression.h"
#include "VisitorDelete.h"

#include <cmath>
#include <iostream>

void ASTInterpreter::run(FunctionExpressionPtr expression)
{
    results.clear();

    expression->accept(*this);
    
    helper.clear();
}

void ASTInterpreter::printResults() const
{
    for(int i = 0; i < results.size(); i++)
    {
        std::cout << results[i] << ' ';
    }
    if(results.size() > 1)
    {
        std::cout << results.size();
    }
}

double ASTInterpreter::getResult() const
{
    return results[0];
}

void ASTInterpreter::visit(LiteralNumber* f)
{
    results.push_back(f->val);
}

void ASTInterpreter::visit(AddFunction* f)
{
    f->left->accept(*this); 
    f->right->accept(*this);

    double temp = results[results.size() - 1] + results[results.size() - 2];

    results.pop_back();
    results.pop_back();

    results.push_back(temp);
}

void ASTInterpreter::visit(SubFunction* f)
{
    f->left->accept(*this); 
    f->right->accept(*this);

    const double temp =  results[results.size() - 2] - results[results.size() - 1];
 
    results.pop_back();
    results.pop_back();
    results.push_back(temp);
}

void ASTInterpreter::visit(MulFunction* f)
{
    f->left->accept(*this); 
    f->right->accept(*this);

    const double temp = results[results.size() - 1] * results[results.size() - 2];

    results.pop_back();
    results.pop_back();
    results.push_back(temp);
}

void ASTInterpreter::visit(DivFunction* f)
{
    f->left->accept(*this); 
    f->right->accept(*this);
 
    const double temp = results[results.size() - 2] / results[results.size() - 1];
 
    results.pop_back();
    results.pop_back();
    results.push_back(temp);
}

void ASTInterpreter::visit(PowFunction* f)
{
    f->base->accept(*this); 
    f->exponent->accept(*this);
   
    const double temp = std::pow(results[results.size() - 2], results[results.size() - 1]);
   
    results.pop_back();
    results.pop_back();
    results.push_back(temp);
}

void ASTInterpreter::visit(ListFunction* f)
{
    for(int i = 0; i < f->values.size(); i++)
    {
        f->values[i]->accept(*this);
    }
}

void ASTInterpreter::visit(SqrtFunction* f)
{
    f->arg->accept(*this);

    const double temp = std::sqrt(results[results.size()-1]);

    results.pop_back();
    results.push_back(temp);
}

void ASTInterpreter::visit(FactorialFunction* f)
{
    f->arg->accept(*this);

    int result = 1;
    int fact = results[results.size() - 1];

    for(int i = 1; i <= fact; i++)
    {
        result *= i;
    }

    results.pop_back();
    results.push_back(result);
}

void ASTInterpreter::visit(SinFunction* f)
{
    f->arg->accept(*this);
    
    const double temp = std::sin(results.size()-1);

    results.pop_back();
    results.push_back(temp);
}

void ASTInterpreter::visit(CosFunction* f)
{
    f->arg->accept(*this);
    
    const double temp = std::cos(results.size()-1);

    results.pop_back();
    results.push_back(temp);
}

void ASTInterpreter::visit(LeFunction* f)
{
    f->left->accept(*this);
    f->right->accept(*this);

    bool temp;
    if(results[results.size() - 2] <= results[results.size() - 1])
    {
        temp = true;
    }
    else
    {
        temp = false;
    }

    results.pop_back();
    results.pop_back();
    results.push_back(temp);
}

void ASTInterpreter::visit(NandFunction* f)
{
    f->left->accept(*this);
    f->right->accept(*this);

    const bool temp1 = results[results.size() - 2] != 0 ? false: true;
    const bool temp2 = results[results.size() - 1] != 0 ? false: true;
    
    const bool result = temp1 || temp2;

    results.pop_back();
    results.pop_back();
    results.push_back(result);
}

void ASTInterpreter::visit(EqFunction* f)
{
    f->left->accept(*this);
    f->right->accept(*this);

    const bool temp = results[results.size() - 2] == results[results.size() - 1];

    results.pop_back();
    results.pop_back();
    results.push_back(temp);
}

void ASTInterpreter::visit(IfFunction* f)
{
    f->condition->accept(*this);

    const float EPS = 0.001;
    
    const double temp = results[results.size() - 1];
    results.pop_back();
    if(std::abs(temp) < EPS)
    {
        f->elseStatement->accept(*this);
    }
    else
    {
        f->ifStatement->accept(*this);
    }
}

void ASTInterpreter::visit(HeadFunction* f)
{
    int oldSize = results.size();
    f->val->accept(*this);

    const int count = results.size() - oldSize - 1;
    for(int i = 0; i < count; i++)
        results.pop_back();
}

void ASTInterpreter::visit(TailFunction* f)
{
    const int oldSize = results.size();
    f->values->accept(*this);

    TFVector<double>::const_iterator it = results.begin();
    results.erase(it+oldSize);
}

void ASTInterpreter::visit(MapFunction* f)
{
    const int oldSize = results.size();
    f->values->accept(*this);

    FunctionDeclaration decl;

    FunctionCall call;
    call.name = f->functionName;

    LiteralNumber num;
    call.args.resize(1);
    
    int size = results.size();
    for(int i = oldSize; i < size; i++)
    {
        num.val = results[i];
        call.args[0] = &num;
        call.accept(*this);
    }

    for(int i = oldSize, j = 0; i < size; i++, j++)
    {
        results[i] = results[size+j];
    }
    results.resize(size);
}

void ASTInterpreter::visit(FilterFunction* f)
{

}

void ASTInterpreter::visit(FunctionDeclaration* f)
{
    TFUnorderedMap<TFString, FunctionExpressionPtr>::const_iterator it = funcs.find(f->name);
    if(it == funcs.end())
    {
        funcs[f->name] = f->body;
        f->body = nullptr;
        return;
    }

    setError(f->getLine(), f->getColumn(), "function redefenition.");
}

void ASTInterpreter::visit(FunctionCall* f)
{

    for(int i = 0; i < f->args.size(); i++)
        f->args[i]->accept(*this);

    helper.clear();

    for(int i = results.size() - f->args.size(); i < results.size(); i++)
        helper.push_back(results[i]);

    for(int i = 0; i < f->args.size(); i++)
        results.pop_back();

    TFUnorderedMap<TFString, FunctionExpressionPtr>::const_iterator it = funcs.find(f->name);
    if(it != funcs.end())
    {
        funcs[f->name]->accept(*this);
        return;
    }

    setError(f->getLine(), f->getColumn(), "undefined function.");
}

void ASTInterpreter::visit(PlaceholderDeclaration* f)
{
    results.push_back(helper[f->index]);
}

void ASTInterpreter::deleteTree(FunctionExpressionPtr root)
{
    VisitorDelete del;
    root->accept(del);
}

ASTInterpreter::~ASTInterpreter()
{
    TFUnorderedMap<TFString, FunctionExpressionPtr>::const_iterator it;

    for(it = funcs.begin(); it != funcs.end(); ++it)
    {
        deleteTree(it->second);
    }
}

void ASTInterpreter::setError(unsigned line, unsigned column, const TFString& what) 
{
    error = TFError{line, column, "Error: " + what};
}