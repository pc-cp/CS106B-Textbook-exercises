

#include <iostream>
#include "mypqueue.h"
using namespace std;

int main() {
    MyPQueue<int> pqueue;
    pqueue.enqueue(2, 1.0);
    assert(pqueue.size() == 1);
    assert(pqueue.peek() == 2);
    pqueue.dequeue();
    assert(pqueue.size() == 0);
    for(int i = 0; i < 10; i ++) {
        pqueue.enqueue(i, (10-i)*1.0);
    }
    assert(pqueue.size() == 10);
    pqueue.enqueue(11, 0.1);
    assert(pqueue.size() == 11);
    assert(pqueue.peek() == 11);
    while(!pqueue.isEmpty()) {
        cout << pqueue.dequeue() << endl;
    }


    MyPQueue<char> pqueue2;
    pqueue2.enqueue('A', 1.0);
    pqueue2.enqueue('C', 0.9);
    pqueue2.enqueue('B', 0.8);
    pqueue2.enqueue('E', 0.7);
    pqueue2.reverse();

    // while(!pqueue2.isEmpty()) {
    //     cout << pqueue2.dequeue() << endl;
    // }
    pqueue2.enqueue('G', 0.6);
    while(!pqueue2.isEmpty()) {
        cout << pqueue2.dequeue() << endl;
    }
    cout << "class MyPQueue is pass unit test successfully." << endl;
    return 0;
}
