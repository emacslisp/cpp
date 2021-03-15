#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include "./lib/Tree.h"
using namespace std;

#define ll long long

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL) return 0;

        int maxLeft = 1 + maxDepth(root->left);
        int maxRight = 1 + maxDepth(root->right);
        return max(maxLeft, maxRight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        int d = l+r;
        return max(d, 
                   max(diameterOfBinaryTree(root->left), 
                       diameterOfBinaryTree(root->right)));
    }
};

int main() {
    Solution s;
    #define null -1
    vector<int> c
    {
        4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-10,-4,null,null,null,-2
       // 1,2,3,4,5
    };

    TreeNode* root;
    Tree t;
    root = t.buildNode(c);
    int result = s.diameterOfBinaryTree(root);
    cout<<result<<endl;
}