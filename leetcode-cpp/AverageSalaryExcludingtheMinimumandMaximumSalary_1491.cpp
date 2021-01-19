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
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double total = 0;

        for(int i=1;i<=salary.size()-2;i++) {
            total += salary[i];
        }

        return total/(salary.size() - 2);
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       8000,9000,2000,3000,6000,1000
    };

    double result = s.average(c);
    cout<<result<<endl;
}