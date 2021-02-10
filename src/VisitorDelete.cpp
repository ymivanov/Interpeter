#include "VisitorDelete.h"

void VisitorDelete::visit(LiteralNumber* f)
{
    delete f;
}

void VisitorDelete::visit(AddFunction* f)
{
    if(f->left)
    {
        f->left->accept(*this);
    }
    if(f->right)
    {
        f->right->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(SubFunction* f)
{
    if(f->left)
    {
        f->left->accept(*this);
    }
    if(f->right)
    {
        f->right->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(MulFunction* f)
{
    if(f->left)
    {
        f->left->accept(*this);
    }
    if(f->right)
    {
        f->right->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(DivFunction* f)
{
    if(f->left)
    {
        f->left->accept(*this);
    }
    if(f->right)
    {
        f->right->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(PowFunction* f)
{
    if(f->base)
    {
        f->base->accept(*this);
    }
    if(f->exponent)
    {
        f->exponent->accept(*this);
    }        
    delete f;
}

void VisitorDelete::visit(SqrtFunction* f)
{
    if(f->arg)
    {
        f->arg->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(FactorialFunction* f)
{
    if(f->arg)
    {
        f->arg->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(SinFunction* f)
{
    if(f->arg)
    {
        f->arg->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(CosFunction* f)
{
    if(f->arg)
    {
        f->arg->accept(*this);
    }
    delete f;
}


void VisitorDelete::visit(LeFunction* f)
{
    if(f->left)
    {
        f->left->accept(*this);
    }
    if(f->right)
    {
        f->right->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(NandFunction* f)
{
    if(f->left)
    {
        f->left->accept(*this);
    }
    if(f->right)
    {
        f->right->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(EqFunction* f)
{
    if(f->left)
    {
        f->left->accept(*this);
    }
    if(f->right)
    {
        f->right->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(IfFunction* f)
{
    if(f->condition)
    {
        f->condition->accept(*this);
    }
    if(f->ifStatement)
    {
        f->ifStatement->accept(*this);
    }
    if(f->elseStatement)
    {
        f->elseStatement->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(ListFunction* f)
{
    for(int i = 0; i < f->values.size(); i++)
    {
        if(f->values[i])
        {
            f->values[i]->accept(*this);
        }
    }
    delete f;
}

void VisitorDelete::visit(HeadFunction* f)
{
    if(f->val)
    {
        f->val->accept(*this);
    }
    delete f;
}
void VisitorDelete::visit(TailFunction* f)
{
    if(f->values)
    {
        f->values->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(MapFunction* f)
{
    if(f->values)
    {
        f->values->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(FilterFunction* f)
{
    if(f->values)
    {
        f->values->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(FunctionDeclaration* f)
{
    if(f->body)
    {
        f->body->accept(*this);
    }
    delete f;
}

void VisitorDelete::visit(PlaceholderDeclaration* f)
{
    delete f;
}

void VisitorDelete::visit(FunctionCall* f)
{
    for(int i = 0; i < f->args.size(); i++)
    {
        if(f->args[i])
        {
            f->args[i]->accept(*this);
        }
    }
    delete f;
}