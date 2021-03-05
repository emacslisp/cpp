#include "ArrayHelper.h"

int ArrayHelper::minimumPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 1; i < n; i++)
    {
        grid[0][i] += grid[0][i - 1];
    }

    for (int i = 1; i < m; i++)
    {
        grid[i][0] += grid[i - 1][0];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[m - 1][n - 1];
}

void ArrayHelper::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ArrayHelper::bubbleSort(vector<int> &nums) {
    int N = nums.size();
    for(int i = 0; i< N;i++) {
        for(int j=0;j<N-1;j++) {
            if(nums[j] > nums[j+1]) {
                swap(&nums[j], &nums[j+1]);
            }
        }
    }
}

vector<int> ArrayHelper::revert(vector<int> c) {
    /*vector<int> result;
    for(int i=c.size()-1;i>=0;i--) {
        result.push_back(c[i]);
    }*/
    reverse(c.begin(), c.end());
    return c;
}

// in O(n) using prefix sum and hash map
int ArrayHelper::subArrayEqualsK(vector<int> nums, int k) {
        vector<int> v;
        int sum = 0;
        v.push_back(sum);

        for(int x: nums) {
            sum+=x;
            v.push_back(sum);
        }

        map<int, int> m;
        int count = 0;
        for(int i=0;i<v.size();i++) {
            int t = v[i];
            if(m.count(t-k) > 0) 
                count+=m[t-k];
            m[t]++;
        }
        return count;
}

int ArrayHelper::maxSubArray(vector<int> nums) {
    if(nums.size() == 1)return nums[0];
      
        int sum = 0;
       int maxSum = INT32_MIN;
      for(int i =0;i<nums.size();i++){
        if(sum < 0){
          sum = nums[i];
        }else{
          sum += nums[i];
        }
        
        maxSum = max(sum , maxSum);
      }
      
      return maxSum > sum ? maxSum : sum;
}

vector<int> ArrayHelper::intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int, int> m1;
        map<int, int> m2;
        for(int x: nums1) m1[x]++;
        for(int x: nums2) m2[x]++;

        for(auto x: m1) {
            if(m2.count(x.first) > 0) {
                int p = min(x.second, m2[x.first]);
                for(int i=0;i<p;i++) {
                    result.push_back(x.first);
                }
            }
        }
        return result;
}

int ArrayHelper::search(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
    }

    return -1;
}

void ArrayHelper::MainEntry() {
    vector<int> c = {
        -2,1,-3,4,-1,2,1,-5,4
    };
    ArrayHelper a;

    cout << "================= ArrayHelper =====================" << endl;
    cout << "maxSubArray: " << a.maxSubArray(c) << endl;

    a.bubbleSort(c);
    for(int x: c) {
        cout << x << " ";
    }
    cout << endl;

    int result = a.search(c, -5);
    cout << "find -5's index in array " << result << endl;

    result = a.subArrayEqualsK(c, 5);
    cout << "number of sub array equals 5: " << result << endl;

     vector<vector<int>> grid
    {{1,2,3},{4,5,6}};

    cout << "minimum path is " << a.minimumPathSum(grid) << endl;
}