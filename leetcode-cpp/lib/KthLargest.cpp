#include "KthLargest.h"

KthLargest::KthLargest(int k, vector<int>& nums) {
    this->k = k;
    for(int x: nums) {
        q.push(x);
    }
}

KthLargest::KthLargest() {

}

int KthLargest::add(int val) {
    q.push(val);
    while(q.size() > this->k) {
        q.pop();
    }
    
    return q.top();
}

void KthLargest::MainEntry() {
    cout << "=============== KthLargest ==============" << endl;
    vector<int> v {
        4, 5, 8 , 2
    };
    KthLargest k(3, v);
    int r = k.add(3);
    cout << r << endl;
    r = k.add(5);
    cout << r << endl;
    r = k.add(10);
    cout << r << endl;
    r = k.add(9);
    cout << r << endl;
    r = k.add(4);
    cout << r << endl;
}