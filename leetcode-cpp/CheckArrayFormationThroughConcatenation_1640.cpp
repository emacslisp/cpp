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
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, int> m;
        vector<int> result(arr.size(), 0);

        for(int i=0;i<arr.size();i++) {
            m[arr[i]] = i; 
        }

        for (vector<int> row : pieces) {
            if(m.count(row[0]) == 0) return false;

            int startIndex = m[row[0]];

            for (int i=0;i<row.size();i++) {
                
                if(i+startIndex >= arr.size()) return false;

                result[startIndex + i] = 1;
                if(row[i] != arr[i+startIndex]) {
                    return false;
                }
            }
        }

        bool output = true;

        for(int x: result) {
            if(x!=1)
            return false;
        }

        return output;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       49,18,16
    };

    vector<vector<int>> pieces
    {
       {16,18,49}
    };

    string str = "codeleet";

    bool result = s.canFormArray(c, pieces);
    cout<<result<<endl;
}