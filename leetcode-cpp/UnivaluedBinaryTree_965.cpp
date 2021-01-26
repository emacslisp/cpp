#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include "./lib/Tree.h"

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    bool foo(TreeNode *root, int value) {
        if(root == NULL) return true;

        if(root->val != value) {
            return false;
        }
        return foo(root->left, root->val) && foo(root->right, root->val);
    }
    bool isUnivalTree(TreeNode* root) {
        return foo(root, root->val);
    }
};

int main() {
    Solution s;
    Tree t;
    #define null -1
    vector<int> c
    {
       2,2,2,5,2
    };

    TreeNode * root = t.buildNode(c);

    bool result = s.isUnivalTree(root);
    cout<<result<<endl;
}