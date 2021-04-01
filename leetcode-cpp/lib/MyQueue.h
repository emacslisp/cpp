#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

class MyQueue {
public:
    stack<int> f;
    stack<int> e;

    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        e.push(x);    
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(f.size() == 0) {
            while(e.size() > 0) {
                f.push(e.top());
                e.pop();
            }
        }

        int t = f.top();
        f.pop();
        return t;
    }
    
    /** Get the front element. */
    int peek() {
        if(f.size() == 0) {
            while(e.size() > 0) {
                f.push(e.top());
                e.pop();
            }
        }
        return f.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return f.size() + e.size() == 0;
    }

    int MainEntry();
};
