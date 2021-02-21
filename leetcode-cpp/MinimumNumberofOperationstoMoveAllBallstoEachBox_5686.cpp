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
    vector<int> minOperations(string boxes) {
        vector<int> position;
        vector<int> result;
        for(int i=0;i<boxes.size();i++) {
            if(boxes[i] == '1') {
                position.push_back(i);
            }
        }

        for(int i=0;i<boxes.size();i++) {
            int sum = 0;
            for(int x: position) {
                sum += abs(x-i);
            }
            result.push_back(sum);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "110";

    vector<int> result = s.minOperations(str);
    for(int x: result)
        cout<<x<<endl;
}