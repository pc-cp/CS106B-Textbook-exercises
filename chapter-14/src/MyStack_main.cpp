
#include <iostream>
#include "mystack.h"
using namespace std;

int main() {
    MyStack<char> stack;

    stack.push('A');
    assert(stack.size() == 1);
    assert(stack.peek() == 'A');
    stack.push('C');
    stack.push('E');
    assert(stack.size() == 3);
    stack.pop();
    assert(stack.size() == 2);
    stack.pop();
    stack.pop();
    assert(stack.isEmpty());

    cout << "class MyStack is pass unit test successfully." << endl;
    return 0;
}
