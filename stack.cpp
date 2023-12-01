#include "stack.h"
#include <iostream>
using namespace std;

void createStack(stack &S)
{
    S.top = 0;
}

int getPresedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void push(stack &S, char p)
{
    if (S.top != m)
    {
        S.top++;
        S.t[S.top] = p;
    }
}

void pop(stack &S, char &p)
{
    if (S.top != 0)
    {
        p = S.t[S.top];
        S.top--;
    }
}

void pushint(stack &S, int p)
{
    if (S.top != m)
    {
        S.top++;
        S.p[S.top] = p;
    }
}

void popint(stack &S, int &p)
{
    if (S.top != 0)
    {
        p = S.p[S.top];
        S.top--;
    }
}

void reverse(string txt, string &newtxt)
{
    char reversed;
    for (int i = txt.length() - 1; i >= 0; i--)
    {
        if (txt[i] == ')')
        {
            txt[i] = '(';
        }
        else if (txt[i] == '(')
        {
            txt[i] = ')';
        }
        newtxt += txt[i];
    }
}

void infixToPostfix(string &infix, string &postfix)
{
    stack S;
    char p;
    createStack(S);

    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9'))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            push(S, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (S.top != 0 && S.t[S.top] != '(')
            {
                postfix += S.t[S.top];
                pop(S, p);
            }
            pop(S, p);
        }
        else
        {
            while (S.top != 0 && getPresedence(S.t[S.top]) >= getPresedence(infix[i]))
            {
                postfix += S.t[S.top];
                pop(S, p);
            }
            push(S, infix[i]);
        }
    }
    while (S.top != 0)
    {
        postfix += S.t[S.top];
        pop(S, p);
    }
}

void infixToPrefix(string infix, string &prefix)
{
    string revtxt, postfix;
    reverse(infix, revtxt);
    infixToPostfix(revtxt, postfix);
    reverse(postfix, prefix);
}

void evaluatePostfix(string x, int &hasil)
{
    stack s;
    createStack(s);
    int num, num1, num2, p, pow;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] >= '0' && x[i] <= '9')
        {
            num = x[i] - 48;
            pushint(s, num);
        }
        else
        {
            num1 = s.p[s.top];
            popint(s, p);
            num2 = s.p[s.top];
            popint(s, p);
            if (x[i] == '+')
            {
                pushint(s, num2 + num1);
            }
            else if (x[i] == '-')
            {
                pushint(s, num2 - num1);
            }
            else if (x[i] == '*')
            {
                pushint(s, num2 * num1);
            }
            else if (x[i] == '/')
            {
                pushint(s, num2 / num1);
            }
            else if (x[i] == '^')
            {
                pow = 1;
                for (int i = 1; i <= num1; i++)
                {
                    pow = pow * num2;
                }
                pushint(s, pow);
            }
        }
    }
    hasil = s.p[s.top];
}

void evaluatePrefix(string x, int &hasil)
{
    stack s;
    createStack(s);
    string revx;
    reverse(x, revx);
    int num, num1, num2, p, pow;
    for (int i = 0; i < revx.length(); i++)
    {
        if (revx[i] >= '0' && revx[i] <= '9')
        {
            num = revx[i] - 48;
            pushint(s, num);
        }
        else
        {
            num1 = s.p[s.top];
            popint(s, p);
            num2 = s.p[s.top];
            popint(s, p);
            if (revx[i] == '+')
            {
                pushint(s, num1 + num2);
            }
            else if (revx[i] == '-')
            {
                pushint(s, num1 - num2);
            }
            else if (revx[i] == '*')
            {
                pushint(s, num1 * num2);
            }
            else if (revx[i] == '/')
            {
                pushint(s, num1 / num2);
            }
            else if (revx[i] == '^')
            {
                pow = 1;
                for (int i = 1; i <= num2; i++)
                {
                    pow = pow * num1;
                }
                pushint(s, pow);
            }
        }
    }
    hasil = s.p[s.top];
}