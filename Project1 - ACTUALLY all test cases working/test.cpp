#include <iostream>
#include "stack_p1.h"

using namespace std;

int main()
{
    // Empty stack
    stack_p1<int> stack;
    stack.push(0);
    stack.push(1);
    stack.push(2);
 
    // Printing content of stack
    while (!stack.isEmpty()) {
        cout << ' ' << stack.peek();
        stack.pop();
    }

 //cout << stack.pop() << "11 <-      -> 12" << stack.pop() << endl;

    return 0;
}