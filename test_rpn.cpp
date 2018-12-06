#include "include/rpn/rpn.h"
#include "include/rpn/stack_queue/queue.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char const* argv[]) {
    // init
    Queue<Token*> infix = Queue<Token*>();

    cout << "enter an infix expression: ";
    string input;
    getline(cin, input);

    infix = tokenize(input);

    // print infix expression
    cout << "infix: ";
    for (auto it = infix.begin(); it != NULL; it++) {
        cout << **it << " ";
    }
    cout << endl;

    // print postfix expression
    cout << "postfix: ";
    Queue<Token*> postfix = infix_to_postfix(infix);
    for (auto it = postfix.begin(); it != NULL; it++) {
        cout << **it << " ";
    }
    // eval
    double result = eval(postfix);

    cout << endl;
    cout << result << endl;

    cout << endl;
    system("pause");
    return 0;
}