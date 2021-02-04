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

void ArrayHelper::MainEntry() {
    vector<int> c = {
        -2,1,-3,4,-1,2,1,-5,4
    };
    ArrayHelper a;

    cout << "================= ArrayHelper =====================" << endl;
    cout << "maxSubArray: " << a.maxSubArray(c) << endl;
}