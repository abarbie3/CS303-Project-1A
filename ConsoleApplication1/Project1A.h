#pragma once
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

template <typename T>
class myStack_with_vector {
private:
    vector<T> items;  // Use a vector to store stack elements

public:
    // Push an item onto the stack
    void push(T item) {
        items.push_back(item);
    }

    // Pop the top item off the stack
    void pop() {
        if (items.empty()) {
            throw runtime_error("Stack is empty: Attempt to pop an element");
        }
        items.pop_back();
    }

    // Access the top item of the stack
    T top() const {
        if (items.empty()) {
            throw runtime_error("Stack is empty: Attempt to access top element");
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

int precedence(char operator_);
int applyOperator(int a, int b, char operator_);
int infixEvaluator(const string& expression); 
