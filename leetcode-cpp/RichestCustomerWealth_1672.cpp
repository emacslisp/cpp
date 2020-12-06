#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for(vector<int> itr: accounts) {
            int total = 0;
            for(int num : itr ) {
                total += num;
            }

            if(total > max)
                max = total;
        }

        return max;
    }
};

int main() {
    Solution s;
    vector<vector<int>> accounts
    {
        {1, 5},
        {7, 3},
        {3, 5}
    };

    int result = s.maximumWealth(accounts);
    cout<< result << endl;
}