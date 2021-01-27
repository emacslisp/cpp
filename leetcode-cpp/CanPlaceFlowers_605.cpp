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

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        vector<int> m;
        m.push_back(0);
        for (int i = 0; i < flowerbed.size(); i++)
        {
            m.push_back(flowerbed[i]);
        }
        m.push_back(0);

        int continued = 0;
        int count = 0;
        for (int i = 0; i < m.size(); i++)
        {
            if (m[i] == 0)
                continued++;
            else
            {
                continued = 0;
            }

            if (continued == 3)
            {
                count++;
                continued = 1;
            }
        }
        return count >= n;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,0,0,0,0,0, 0, 0, 1
    };

    string str = "codeleet";

    int n = 3;
    bool result = s.canPlaceFlowers(c, n);
    cout<<result<<endl;
}