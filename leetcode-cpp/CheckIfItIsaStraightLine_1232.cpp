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
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        bool result = true;
        if (coordinates[1][0] == coordinates[0][0])
        {
            for (int i = 2; i < coordinates.size(); i++)
            {
                if(coordinates[i][0] == coordinates[0][0]) {

                } else{
                    result = false;
                    break;
                }
            }

            return result;
        }

        double scope = ((double)(coordinates[1][1] - coordinates[0][1])) / ((double)(coordinates[1][0] - coordinates[0][0]));
        
        for (int i = 2; i < coordinates.size(); i++)
        {
            double scope2 = ((double)(coordinates[i][1] - coordinates[0][1])) / ((double)(coordinates[i][0] - coordinates[0][0]));
            if (scope == scope2)
            {
                continue;
            }
            else
            {
                result = false;
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> c{
        {2, 1}, {4, 2}, {6, 3}
    };

    string str = "codeleet";

    bool result = s.checkStraightLine(c);
    cout << result << endl;
}