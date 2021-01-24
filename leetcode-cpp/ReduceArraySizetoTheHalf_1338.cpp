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

   bool cmp(pair<int, int>& a, 
            pair<int, int>& b) 
    { 
        return a.second > b.second; 
    }

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        vector<pair<int, int>> result;

        for(int i=0;i<arr.size();i++) {
            if(m.count(arr[i]) > 0) {
                m[arr[i]] += 1;
            } else {
                m[arr[i]] = 1;
            }
        }

        for (auto& it: m) {
            result.push_back(it);
        }

        sort(result.begin(), result.end(), cmp);

        int output = 0;
        int sum = 0;
        for(pair<int, int> a: result) {
            sum += a.second;
            output++;
            if(sum >= arr.size()/2) {
                break;
            }
        }
        return output;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       83540,79940,50658,44620,35146,5842,53172,11867,43496,14991,45916,70814,26510,75319,14226,16099,96652,6339,84655,26270,21110,29451,2541,8098,49688,17237,36937,40975,88382,30544,10152,15235,18140,17523,5125,41399,11001,76986,57821,55723,71103,81290,21120,72293,4229,74250,91623,73878
    };

    string str = "codeleet";

    int result = s.minSetSize(c);
    cout<<result<<endl;
}