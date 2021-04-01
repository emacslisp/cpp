#include "MyQueue.h"

int MyQueue::MainEntry() {
    cout << "================= MyQueue =====================" <<endl;

    MyQueue q;
    
    q.push(1);
    q.push(2);
    int result = q.peek();
    cout << result << endl;
    result = q.pop();
    cout << result << endl;
    bool b = q.empty();
    cout << b << endl;
    return 0;
}