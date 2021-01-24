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
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max = 0;
        int counter = 0;
        for(int i=0;i<rectangles.size();i++) {
            int t = Min(rectangles[i][0], rectangles[i][1]);
            if(max < t) {
                max = t;
                counter = 1;
            } else if(max == t) {
                counter++;
            }
        }
        return counter;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{2,3},{3,7},{4,3},{3,7}};

    string str = "codeleet";

    int result = s.countGoodRectangles(c);
    cout<<result<<endl;
}