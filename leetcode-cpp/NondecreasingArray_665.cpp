#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;

        int counter = 0;
        int t = 0;
        int m = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                counter++;
                t = i - 1;
            }
        }

        if (counter > 2)
        {
            return false;
        }
        else if (counter == 0)
        {
            return true;
        }
        else if (counter == 1)
        {
            // only check two possible of counter == 1
            for (int i = 1; i <= t; i++)
            {
                if (m < nums[i - 1])
                {
                    m = nums[i - 1];
                }
            }

            int c1 = 0;
            int c2 = 0;
            int temp = nums[t];
            nums[t] = m;

            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i - 1] > nums[i])
                {
                    c1++;
                }
            }

            nums[t] = temp;

            if (c1 == 0)
                return true;

            temp = nums[t + 1];
            nums[t + 1] = max(m, nums[t]);

            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i - 1] > nums[i])
                {
                    c2++;
                }
            }

            nums[t + 1] = temp;

            if (c2 == 0)
                return true;

            return false;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> c{5, 7, 1, 8};

    bool result = s.checkPossibility(c);
    cout << result << endl;
}