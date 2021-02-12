#include "ArrayHelper.h"

vector<int> ArrayHelper::revert(vector<int> c) {
    /*vector<int> result;
    for(int i=c.size()-1;i>=0;i--) {
        result.push_back(c[i]);
    }*/
    reverse(c.begin(), c.end());
    return c;
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

void ArrayHelper::MainEntry() {
    vector<int> c = {
        -2,1,-3,4,-1,2,1,-5,4
    };
    ArrayHelper a;

    cout << "================= ArrayHelper =====================" << endl;
    cout << "maxSubArray: " << a.maxSubArray(c) << endl;
}