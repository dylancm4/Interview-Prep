//
//  MinStack.cpp
//  
//
//  Created by Dylan Miller on 2/20/17.
//
//

/*
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 
 push(x) – Push element x onto stack.
 pop() – Removes the element on top of the stack.
 top() – Get the top element.
 getMin() – Retrieve the minimum element in the stack.
 Note that all the operations have to be constant time operations.
 
 Questions to ask the interviewer :
 
 Q: What should getMin() do on empty stack?
 A: In this case, return -1.
 
 Q: What should pop do on empty stack?
 A: In this case, nothing.
 
 Q: What should top() do on empty stack?
 A: In this case, return -1
 NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor.
 */

class MinVal
{
public:
    MinVal(int _val, int _count) :  val(_val), count(_count) {}
    int val;
    int count;
};

stack<int> valStack;
stack<MinVal> minStack;

MinStack::MinStack()
{
    while (valStack.size())
        valStack.pop();
    while (minStack.size())
        minStack.pop();
}

void MinStack::push(int x)
{
    if (!minStack.size() || x < minStack.top().val)
        minStack.push(MinVal(x, 1));
    else if (x == minStack.top().val)
        minStack.top().count++;
    valStack.push(x);
}

void MinStack::pop()
{
    if (valStack.size())
    {
        if (valStack.top() == minStack.top().val)
        {
            if (minStack.top().count > 1)
                minStack.top().count--;
            else
                minStack.pop();
        }
        valStack.pop();
    }
}

int MinStack::top()
{
    return valStack.size() ? valStack.top() : -1;
}

int MinStack::getMin()
{
    return minStack.size() ? minStack.top().val : -1;
}

// Difficulty: Easy. This was made more difficult by a few things. One, interviewbit did not allow declaring the class, so global variables had to be used. Two, the problem listed no space requirements, yet the submit tests tested for space requirements. Three, an std::list failed the time requirements while an std::stack did not, which doesn't make much sense, since both have the same time complexity for the operations used, and in fact the reason I used std::list to start with is that it has a clear() function, so I thought it might be more efficient than std::stack for this problem.
