
#include <iostream>
#include "myqueue.h"
using namespace std;

int main() {
    MyQueue<int> queue;
    queue.enqueue(2);
    assert(queue.size() == 1);
    assert(queue.peek() == 2);
    queue.dequeue();
    assert(queue.size() == 0);
    for(int i = 0; i < 10; i ++) {
        queue.enqueue(i);
    }
    assert(queue.size() == 10);
    queue.enqueue(11);
    assert(queue.size() == 11);
    assert(queue.peek() == 0);

    MyQueue<char> queue2;
    queue2.enqueue('A');
    cout << "class MyQueue is pass unit test successfully." << endl;
    return 0;
}
