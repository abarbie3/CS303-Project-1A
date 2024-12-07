#include "Project1A.h"

//Check for operator precedence
int precedence(char operator_) {
    if (operator_ == '||') return 1;
    if (operator_ == '&&') return 2;
    if (operator_ == '==' || operator_ == '!=') return 3;
    if (operator_ == '>' || operator_ == '>=' || operator_ == '<' || operator_ == '<=') return 4; 
    if (operator_ == '+' || operator_ == ' -') return 5;
    if (operator_ == '*' || operator_ == '/' || operator_ == '%') return 6;
    if (operator_ == '^') return 7;
    if (operator_ == '--' || operator_ == '++' || operator_ == '!') return 8;

    return 0;
}

//Applies operator for evaluation
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
        return (a < b) ? 1 : 0;
    case '>': return 0;
        return (a > b) ? 1 : 0;
    case '==':
        return (a == b) ? 1 : 0;
    case '!=':
        return (a != b) ? 1 : 0;
    }

    throw invalid_argument("Unknown operator: " + operator_);
   
    return 0;
}

//Evaluates expressions using infix
int infixEvaluator(const string& expression) {
    myStack_with_vector<int> operands;
    myStack_with_vector<char> operators;

    //Checks, error handles, and evaluates expressions
    for (size_t i = 0; i < expression.length(); i++) {
        if (isspace(expression[i])) continue;

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
    cout << operands.top();
    return operands.top();
}
