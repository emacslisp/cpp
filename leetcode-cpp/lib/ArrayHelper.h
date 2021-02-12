#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

class ArrayHelper {
public:
    vector<int> revert(vector<int> c);
    int maxSubArray(vector<int> c);
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
    void MainEntry();
};