//Names: Alyssa Barbee
//Date: 
//CS303 Project 1A

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

template <typename T>
class myStack_with_vector {
private:
    std::vector<T> items;  // Use a vector to store stack elements

public:
    // Push an item onto the stack
    void push(T item) {
        items.push_back(item);
    }

    // Pop the top item off the stack
    void pop() {
        if (items.empty()) {
            throw std::runtime_error("Stack is empty: Attempt to pop an element");
        }
        items.pop_back();
    }

    // Access the top item of the stack
    T top() const {
        if (items.empty()) {
            throw std::runtime_error("Stack is empty: Attempt to access top element");
        }
        return items.back();
    }

    // Check if the stack is empty
    bool empty() const {
        return items.empty();
    }

    // Get the size of the stack
    size_t size() const {
        return items.size();
    }
};

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
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
    }
    return 0;
}

int evaluate(const std::string& expression) {
    myStack_with_vector<int> values;
    myStack_with_vector<char> operators;

    for (size_t i = 0; i < expression.length(); i++) {
        if (isspace(expression[i])) continue;

        if (isdigit(expression[i])) {
            int value = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                value = (value * 10) + (expression[i] - '0');
                i++;
            }
            values.push(value);
            i--;
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int value2 = values.top();
                values.pop();
                int value1 = values.top();
                values.pop();
                char operator_ = operators.top();
                operators.pop();
                values.push(applyOperator(value1, value2, operator_));
            }
            if (!operators.empty()) operators.pop();
        } else if (expression[i] == '+' || expression[i] == '-' ||
                   expression[i] == '*' || expression[i] == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                int value2 = values.top();
                values.pop();
                int value1 = values.top();
                values.pop();
                char operator_ = operators.top();
                operators.pop();
                values.push(applyOperator(value1, value2, operator_));
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        int value2 = values.top();
        values.pop();
        int value1 = values.top();
        values.pop();
        char operator_ = operators.top();
        operators.pop();
        values.push(applyOperator(value1, value2, operator_));
    }

    return values.top();
}

int main() {
    std::string expression;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, expression);

    try {
        int result = evaluate(expression);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

