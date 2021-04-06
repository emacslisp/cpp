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
    
    void dfs(TreeNode*root, string path, vector<string> &v) {
        if(root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            path += "->" + to_string(root->val);
            v.push_back(path);
            return;
        }
        path += "->" + to_string(root->val);
        dfs(root->left, path, v);
        dfs(root->right, path, v);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(root == NULL) return v;
        string path = to_string(root->val);
        dfs(root->left, path, v);
        dfs(root->right, path, v);
        if(v.size() == 0) {
            v.push_back(path);
        }
        return v;
    }
};

int main() {
    Solution s;
    #define null -1
    vector<int> c
    {
       1,2,3,null,5
    };

    string str = "codeleet";
    int n = 1804289383;
    Tree t;
    TreeNode *root = t.buildNode(c);
    vector<string> result = s.binaryTreePaths(root);
    for(auto x: result)
        cout<<x<<endl;
}