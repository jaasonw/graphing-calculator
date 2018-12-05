#include "include/rpn/rpn.h"
#include "rpn/stack_queue/queue.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;
int main() {
    assert("asdf");
    string input;
    cout << "enter an equation: ";
    Queue<Token*> infix;
    // infix.push(new Operator('('));
    // infix.push(new Operator('('));
    // infix.push(new Operator('('));
    // infix.push(new Operand(1));
    // infix.push(new Operator('+'));
    // infix.push(new Operand(2));
    // infix.push(new Operator(')'));
    // infix.push(new Operator('^'));
    // infix.push(new Operand(2));
    // infix.push(new Operator('*'));
    // infix.push(new Operand(3));
    // infix.push(new Operator(')'));
    // infix.push(new Operator('+'));
    // infix.push(new Operand(4));
    // infix.push(new Operator('*'));
    // infix.push(new Operand(5));
    // infix.push(new Operator(')'));
    // infix.push(new Operator('/'));
    // infix.push(new Operand(6));
    // infix.push(new Operator('+'));
    infix.push(new FunctionToken("sin"));
    infix.push(new Operator('('));
    infix.push(new Operand(7));
    infix.push(new Operator('+'));
    infix.push(new Operand(8));
    infix.push(new Operator(')'));
    
    // for (int i = 0; i < input.size(); i++) {

    // }
    cout << "infix: ";
    for (auto it = infix.begin(); it != NULL; it++) {
        cout << **it << " ";
    }
    cout << endl;
    cout << "postfix: ";
    auto postfix = infix_to_postfix(infix);
    for (auto it = postfix.begin(); it != NULL; it++) {
        cout << **it << " ";
    }
    cout << endl;
    cout << "result: ";
    cout << eval(postfix);
    return 0;
}