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
    double trimMean(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int size = arr.size();
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum+=arr[i];
        }

        int top = size * 5/ 100;
        int count = 0;
        for (int i = 0; i < top; i++)
        {
            sum -= arr[i];
            count++;
        }

        for(int i = size - 1; i>=size-top;i--) {
            sum -= arr[i];
            count++;
        }

        return (double)sum/(double)(size - count);
    }
};

int main()
{
    Solution s;
    vector<int> c{
        6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4
        // 9,7,8,7,7,8,4,4,6,8,8,7,6,8,8,9,2,6,0,0,1,10,8,6,3,3,5,1,10,9,0,7,10,0,10,4,1,10,6,9,3,6,0,0,2,7,0,6,7,2,9,7,7,3,0,1,6,1,10,3
    };

    string str = "codeleet";

    double result = s.trimMean(c);
    cout << result << endl;
}