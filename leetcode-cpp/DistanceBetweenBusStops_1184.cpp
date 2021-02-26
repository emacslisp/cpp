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


class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0;
        vector<int> v;

        v.push_back(sum);
        for(int x: distance) {
            sum+=x;
            v.push_back(sum);
        }

        int target = abs(v[destination] - v[start]);

        return min(target, sum-target);
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       7
    };

    int start = 0;
    int end = 0;

    int result = s.distanceBetweenBusStops(c, start, end);
    cout<<result<<endl;
}