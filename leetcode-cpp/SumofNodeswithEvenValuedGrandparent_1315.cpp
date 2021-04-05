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
    void dfs(TreeNode *root, TreeNode *parent, TreeNode *grandParent, vector<int> &v) {
        if(root == NULL) return;
        
        if(parent != NULL && grandParent != NULL) {
            if(grandParent->val %2 == 0) v.push_back(root->val);
        }

        if(parent != NULL) {
            dfs(root->left, root, parent, v);
            dfs(root->right, root, parent, v);
        }
        else {
            dfs(root->left, root, NULL, v);
            dfs(root->right, root, NULL, v);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        vector<int> v;
        dfs(root, NULL, NULL, v);
        int sum = 0;
        for(int x : v) {
            sum+=x;
        } 
        return sum;
    }
};

int main() {
    Solution s;
    #define null -1
    vector<int> c
    {
       6,7,8,2,7,1,3,9,null,1,4,null,null,null,5
    };

    Tree t;
    TreeNode *root = t.buildNode(c);

    string str = "codeleet";
    int n = 1804289383;
    int result = s.sumEvenGrandparent(root);
    cout<<result<<endl;
}