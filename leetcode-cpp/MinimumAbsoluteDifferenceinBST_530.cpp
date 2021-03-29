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
    void dfs(TreeNode *root, vector<int> &v) {
        if(root == NULL) return;
        v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> v;

        dfs(root, v);
        sort(v.begin(), v.end());
        int diff = v[v.size()-1] -v[0];
        for(int i=0;i<v.size()-1;i++) {
            int t = abs(v[i+1] - v[i]);
            if(diff > t) {
                diff = t;
            }
        }
        return diff;
    }
};

int main() {
    Solution s;
    #define null -1
    vector<int> c
    {
       1, null, 5, 10
    };

    string str = "codeleet";
    int n = 1804289383;
    TreeNode* root;
    Tree t;
    root = t.buildNode(c);
    int result = s.getMinimumDifference(root);
    cout<<result<<endl;
}