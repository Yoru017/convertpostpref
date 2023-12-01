#include "stack.cpp"
#include <iostream>
using namespace std;

int main()
{
    string infix;
    string postfix, prefix;
    string posteval, prefeval;
    int evalpost, evalpref;
    cout << "infix : ";
    cin >> infix;
    // convert
    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);
    cout << postfix << endl;
    cout << prefix << endl;

    // evaluate
    evaluatePostfix(postfix, evalpost);
    evaluatePrefix(prefix, evalpref);
    cout << "Prefix : " << evalpref << endl;
    cout << "Postfix : " << evalpost << endl;
}