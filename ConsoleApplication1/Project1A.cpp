#include "Project1A.h"

//ADD: LESS THAN, COMPARISON, 



int precedence(char operator_) {
    if (operator_ == '+' || operator_ == '-') return 1;
    if (operator_ == '*' || operator_ == '/') return 2;
    return 0;
}

int applyOperator(int a, int b, char operator_) {
    switch (operator_) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) throw runtime_error("Division by zero");
        return a / b;
    case '^': return pow(a, b);
    case '<': 
        if (a < b) return 1;
        else return 0;
    case '>': return 0;
        if (a > b) return 1;
        else return 0;
    }
    return 0;
}

int infixEvaluator(const string& expression) {
    myStack_with_vector<int> operands;
    myStack_with_vector<char> operators;

    for (size_t i = 0; i < expression.length(); i++) {
        if (isspace(expression[i])) continue;
        if (expression[i] == '+') continue;

        if (isdigit(expression[i])) {
            int operand = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }
            operands.push(operand);
            i--;
        }
        else if (expression[i] == '(') {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                char operator_ = operators.top();
                operators.pop();
                operands.push(applyOperator(operand1, operand2, operator_));
            }
            if (!operators.empty()) operators.pop();
        }
        else if (expression[i] == '+' || expression[i] == '-' ||
            expression[i] == '*' || expression[i] == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                char operator_ = operators.top();
                operators.pop();
                operands.push(applyOperator(operand1, operand2, operator_));
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        int operand2 = operands.top();
        operands.pop();
        int operand1 = operands.top();
        operands.pop();
        char operator_ = operators.top();
        operators.pop();
        operands.push(applyOperator(operand1, operand2, operator_));
    }

    return operands.top();
}
