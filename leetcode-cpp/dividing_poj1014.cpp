#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

#define Max(a, b) a > b ? a : b

void output(bool isDivided, int collection)
{
    printf("Collection #%d:\n", collection);

    if (isDivided)
    {
        printf("Can be divided.\n");
    }
    else
    {
        printf("Can't be divided.\n");
    }
    printf("\n");
}

int dp[6*20000 + 10][20000 + 10];
bool check(vector<int> nums, int sum)
{
    
    memset(dp, 0 ,sizeof(dp));
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] > sum)
            {
                return false;
            }
            if (nums[j] <= i)
            {
                dp[i][j + 1] = Max(dp[i][j], nums[j] + dp[i - nums[j]][j]);
            }
        }
    }

    if (dp[sum][nums.size()] == sum)
    {
        return true;
    }
    return false;
}

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("dividing_poj1014.in", "r", stdin);
    freopen("dividing_poj1014.out", "w", stdout);
#endif

    int a[6];
    bool isEnd;
    int collection = 0;
    while (true)
    {
        isEnd = true;
        for (int i = 0; i < 6; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] != 0)
            {
                isEnd = false;
            }
        }

        if (isEnd)
        {
            break;
        }

        collection++;
        int sum = 0;
        vector<int> nums;
        for (int i = 0; i < 6; i++)
        {
            sum += a[i] * (i + 1);
            for (int j = 0; j < a[i]; j++)
            {
                nums.push_back(i + 1);
            }
        }

        if (sum % 2 == 1)
        {
            output(false, collection);
            continue;
        }

        sum /= 2;

        bool result = check(nums, sum);

        output(result, collection);
    }

#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}