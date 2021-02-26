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
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while(start <= end) {
            int mid = (start+end)/2;

            if(nums[mid] == target) {
                return mid;
            }

            if(nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target){
                start = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       -1,0,3,5,9,12
    };
    int target = 12;

    int result = s.search(c, target);
    cout<<result<<endl;
}