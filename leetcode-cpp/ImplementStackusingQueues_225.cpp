#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

#define ll long long

class MyStack {
public:
    queue<int> t;
    queue<int> b;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        b.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(b.size() > 1) {
            t.push(b.front());
            b.pop();
        }

        int temp = b.front();
        b.pop();

        while(t.size() > 0) {
            b.push(t.front());
            t.pop();
        }

        return temp;
    }
    
    /** Get the top element. */
    int top() {
        if(t.size() > 0)
            return t.back();

        return b.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return t.size() + b.size() == 0;
    }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    int result = s.top();
    cout << result << endl;
    result = s.pop();
    cout << result << endl;
    bool b = s.empty();
    cout << b << endl;
}