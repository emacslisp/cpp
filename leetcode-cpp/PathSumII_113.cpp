#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include "lib/Tree.h"
using namespace std;

#define ll long long

class Solution {
public:

    void dfs(TreeNode* root, int sum, int targetSum, vector<int> v, vector<vector<int>> &vv) {
        if(root == NULL) return;
        v.push_back(root->val);
        sum += root->val;
        if(root->left == NULL && root->right == NULL) {
            if(sum == targetSum) {
                vv.push_back(v);
            }
            return;
        }

        dfs(root->left, sum, targetSum, v, vv);
        dfs(root->right, sum, targetSum, v, vv);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> vv;
        vector<int> v;

        dfs(root, 0, targetSum, v, vv);
        return vv;
    }
};

int main() {
    Solution s;
    #define null -1
    vector<int> c
    {
     1,2,3
    };

    string str = "codeleet";
    int n = 1804289383;
    Tree t;
    TreeNode * root = t.buildNode(c);
    vector<vector<int>> result = s.pathSum(root, 5);
    for(auto x: result) {
        for(int y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
}