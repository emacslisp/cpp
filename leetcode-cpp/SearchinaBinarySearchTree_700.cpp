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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val == val) {
            return root;
        } else {
            TreeNode* n1 = searchBST(root->left, val);
            TreeNode* n2 = searchBST(root->right, val);
            if(n1 != NULL) return n1;
            if(n2 != NULL) return n2;
        }

        return NULL;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,2,7,1,3
    };

    string str = "codeleet";
    TreeNode* root;
    int val = 2;
    Tree t;
    root = t.buildNode(c);

    TreeNode* result = s.searchBST(root, val);
    cout<<result -> val<<endl;
    cout<<result -> left -> val<<endl;
    cout<<result -> right -> val<<endl;
}