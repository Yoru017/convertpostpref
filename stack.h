#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;

const int m = 100;
struct stack
{
    char t[m];
    int p[m];
    int top;
};

void createStack(stack &S);
void push(stack &S, char p);
void pushint(stack &S, int p);
void pop(stack &S, char &p);
void popint(stack &S, int &p);
void infixToPostfix(string &infix, string &postfix);
int getPresedence(char op);
void reverse(string &txt);
void infixToPrefix(string infix, string &prefix);
void evaluatePrefix(string prefix, int &hasil);
void evaluatePostfix(string postfix, int &hasil);



#endif