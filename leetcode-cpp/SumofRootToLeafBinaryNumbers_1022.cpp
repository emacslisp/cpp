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
    int total;
    void foo(TreeNode *root, int value) {
        if(root == NULL) {
            return;
        }

        int sum = value * 2 + root->val;

        if(root->left == NULL && root->right == NULL) {
            total += sum;
            return;
        }
        foo(root->left, sum);
        foo(root->right, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        total = 0;
        foo(root, 0);
        return total;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,0,1,0,1,0
    };

    Tree t;

    TreeNode * root = t.buildNode(c);
    string str = "codeleet";

    int result = s.sumRootToLeaf(root);
    cout<<result<<endl;
}