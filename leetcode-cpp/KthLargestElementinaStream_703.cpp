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

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int k=0;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int x: nums) {
            q.push(x);
        }
    }
    
    int add(int val) {
        q.push(val);
        while(q.size() > this->k) {
            q.pop();
        }
        
        return q.top();
    }
};

int main() {
    vector<int> nums {
        4, 5, 8, 2
    };
    KthLargest k(3, nums);

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