#include "stack.cpp"
#include <iostream>
using namespace std;

int main()
{
    string infix, postfix, prefix;
    int hasilpost, hasilpref;
    // conv to postfix
    postfix = "";
    cout << "Infix : ";
    cin >> infix;
    infixToPostfix(infix, postfix);
    cout << "Postfix : " << postfix << endl;

    // conv to prefix
    infixToPrefix(infix, prefix);
    cout << "Prefix : " << prefix << endl;

    // evaluate postfix
    cout << "Postfix : ";
    cin >> postfix;
    evaluatePostfix(postfix, hasilpost);
    cout << "Hasil Eval : " << hasilpost << endl;

    //evaluate prefix
    cout << "Prefix : ";
    cin >> prefix;
    evaluatePrefix(prefix, hasilpref);
    cout << "Hasil Eval : " << hasilpref << endl;
}