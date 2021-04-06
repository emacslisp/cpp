#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

class KthLargest {
public:
    priority_queue< int, vector<int>, greater<int> > q;
    int k;
    KthLargest();
    KthLargest(int k, vector<int>& nums);
    
    int add(int val);
    void MainEntry();
};