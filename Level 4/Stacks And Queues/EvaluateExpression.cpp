//
//  EvaluateExpression.cpp
//  
//
//  Created by Dylan Miller on 2/21/17.
//
//

/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 
 Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 
 Examples:
 
 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

enum Operation {ADD, SUBTRACT, MULTIPLY, DIVIDE};
void performOperation(stack<int>& num_stack, Operation operation)
{
    int b = num_stack.top();
    num_stack.pop();
    int a = num_stack.top();
    num_stack.pop();
    
    int c;
    switch (operation)
    {
        case ADD:
            c = a + b;
            break;
        case SUBTRACT:
            c = a - b;
            break;
        case MULTIPLY:
            c = a * b;
            break;
        case DIVIDE:
            c = a / b;
            break;
    }
    num_stack.push(c);
}

int Solution::evalRPN(vector<string> &A)
{
    stack<int> num_stack;
    for (int i = 0; i < A.size(); i++)
    {
        const string& operand = A[i];
        if (operand == "+")
            performOperation(num_stack, ADD);
        else if (operand == "-")
            performOperation(num_stack, SUBTRACT);
        else if (operand == "*")
            performOperation(num_stack, MULTIPLY);
        else if (operand == "/")
            performOperation(num_stack, DIVIDE);
        else
            num_stack.push(atoi(operand.c_str()));
    }
    return num_stack.top();
}

// Difficulty: Easy
