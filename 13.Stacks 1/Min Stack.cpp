/*
Min Stack
Problem Description

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
NOTE:

All the operations have to be constant time operations.
getMin() should return -1 if the stack is empty.
pop() should return nothing if the stack is empty.
top() should return -1 if the stack is empty.


Problem Constraints
1 <= Number of Function calls <= 107



Input Format
Functions will be called by the checker code automatically.



Output Format
Each function should return the values as defined by the problem statement.



Example Input
Input 1:

push(1)
push(2)
push(-2)
getMin()
pop()
getMin()
top()
Input 2:

getMin()
pop()
top()


Example Output
Output 1:

 -2 1 2
Output 2:

 -1 -1


Example Explanation
Explanation 1:

Let the initial stack be : []
1) push(1) : [1]
2) push(2) : [1, 2]
3) push(-2) : [1, 2, -2]
4) getMin() : Returns -2 as the minimum element in the stack is -2.
5) pop() : Return -2 as -2 is the topmost element in the stack.
6) getMin() : Returns 1 as the minimum element in stack is 1.
7) top() : Return 2 as 2 is the topmost element in the stack.
Explanation 2:

Let the initial stack be : []
1) getMin() : Returns -1 as the stack is empty.
2) pop() :  Returns nothing as the stack is empty.
3) top() : Returns -1 as the stack is empty.

*/
// stack<int> st;
// stack<int> minSt;

// MinStack::MinStack() {
//     while(!st.empty()){
//         st.pop();
//     }
//     while(!minSt.empty()){
//         minSt.pop();
//     }
// }

// void MinStack::push(int x) {
//     st.push(x);
//     if(minSt.size() == 0){
//         minSt.push(x);
//     }
//     else{
//         if(x <= minSt.top()){
//             minSt.push(x);
//         }
//         else{
//             minSt.push(minSt.top());
//         }
//     }
// }

// void MinStack::pop() {
//     if(st.size() != 0){
//         st.pop();
//         minSt.pop();
//     }
// }

// int MinStack::top() {
//     if(st.size() == 0){
//         return -1;
//     }
//     return st.top();
// }

// int MinStack::getMin() {
//     if(minSt.size() == 0){
//         return -1;
//     }
//     return minSt.top();
// }

stack < int > elementStack;
stack < int > minimumStack;

int minElement = -1;
MinStack::MinStack() {
    while (elementStack.empty() == false)
        elementStack.pop();
    while (minimumStack.empty() == false)
        minimumStack.pop();
    minElement = -1;
}

void MinStack::push(int x) {
    elementStack.push(x);
    if (elementStack.size() == 1 || x <= minElement) {
        minimumStack.push(x);
        minElement = x;
    }
}

void MinStack::pop() {
    if (elementStack.empty()) return;
    if (elementStack.top() == minElement) {
        minimumStack.pop();
        if (!minimumStack.empty()) {
            minElement = minimumStack.top();
        } else {
            minElement = -1;
        }
    }
    elementStack.pop();
}

int MinStack::top() {
    if (elementStack.empty()) return -1;
    return elementStack.top();
}

int MinStack::getMin() {
    if (elementStack.empty()) return -1;
    return minElement;
}
