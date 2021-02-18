#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include "./lib/Tree.h"

using namespace std;


class Solution {
public:
    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }
        
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, start, mid-1);
        root->right = buildTree(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        return buildTree(nums, start, end);
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       -10,-3,0,5,9
    };

    TreeNode* result = s.sortedArrayToBST(c); 

    Tree tree;
    vector<int> output = tree.buildTreeToArray(result);

    for(int x: output) {
        cout << x << " ";
    }
    cout << endl;
}