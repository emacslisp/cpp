#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;

bool cmp(vector<int>& a, 
            vector<int>& b) 
    { 
        return a[1] > b[1];
    } 

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int result = 0;
        for(int i=0;i<boxTypes.size();i++) {
            vector<int> t = boxTypes[i];
            if(t[0] < truckSize) {
                result += t[0] * t[1];
                truckSize -= t[0];
            } else {
                result += truckSize * t[1];
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {
       {5,10},{2,5},{4,7},{3,9}
    };

    string str = "codeleet";
    int size = 10;
    int result = s.maximumUnits(c, size);
    cout<<result<<endl;
}