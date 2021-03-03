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
    vector<int> c;
    void foo(TreeNode* root) {
        if(root == NULL) return;

        c.push_back(root->val);
        foo(root->left);
        foo(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        foo(root);
        sort(c.begin(), c.end());
        TreeNode *head;
        TreeNode *r = new TreeNode(c[0]);
        head = r;
        for(int i=1;i<c.size();i++) {
            r->right = new TreeNode(c[i]);
            r = r->right;
        }
        return head;
    }
};

#define null -1

int main() {
    Solution s;
    TreeNode* root;
    vector<int> c {
        5,3,6,2,4,null,8,1,null,null,null,7,9
    };

    Tree t;
    root = t.buildNode(c);
    vector<int> vc = t.buildTreeToArray(root);

    for(int x : vc) {
        cout << x << " ";
    }
    cout << endl;

    TreeNode* result = s.increasingBST(root);
    cout<<result->val<<endl;
}