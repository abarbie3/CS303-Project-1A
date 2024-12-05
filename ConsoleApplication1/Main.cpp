//Names: Alyssa Barbee
//Date: 
//CS303 Project 1A

#include "Project1A.h"

int main() {
    string expression;
    cout << "Enter an infix expression: ";
    getline(cin, expression);

    try {
        int result = evaluate(expression);
        cout << "Result: " << result << endl;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

