#include "Project1A.h"

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
        }
        else if (expression[i] == '(') {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')') {
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
        }
        else if (expression[i] == '+' || expression[i] == '-' ||
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

int Postfix_Evaluator(const std::string& expression) {
	// Be sure the stack is empty
	while (!operand_stack.empty())
		operand_stack.pop();
	// Process each token
	istringstream tokens(expression);
	char next_char;
	while (tokens >> next_char) {
		if (isdigit(next_char)) {// if this character is a digit
			tokens.putback(next_char);//put back to the expression string
			int value;
			tokens >> value; //now read the token as a number
			operand_stack.push(value);
		}
		else if (is_operator(next_char)) {
			int result = eval_op(next_char); //evaluate: result= second op first
			operand_stack.push(result); //push the result back to the stack
		}
		else { //an invalid character
			throw Syntax_Error("Invalid character encountered"); //
		}
	}
	if (!operand_stack.empty()) {
		int answer = operand_stack.top(); //the answer should be the top item
		operand_stack.pop();
		if (operand_stack.empty()) { //in the end, the stack should be empty
			return answer;
		}
		else {
			throw Syntax_Error("Stack should be empty");
		}
	}
	else {
		throw Syntax_Error("Stack is empty");
	}
}
