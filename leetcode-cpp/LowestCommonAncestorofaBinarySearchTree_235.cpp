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
#define ld long double
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9+7;
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))


class Solution {
public:
    TreeNode* target;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return false;

        if(root->val == p->val || root->val == q->val) {
            if (dfs(root->left, p, q) || dfs(root->right, p, q)) {
                target = root;
            }

            return true;
        } 
        bool t1 = dfs(root->left, p, q);
        bool t2 = dfs(root->right, p, q);

        if(t1 && t2) {
            target = root;
        }

        return t1||t2;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return target;
    }
};

int main() {
    Solution s;
    #define null -1
    vector<int> c
    {
       6,2,8,0,4,7,9,null,null,3,5
    };
    Tree t;
    TreeNode * root = t.buildNode(c);
    TreeNode * p = t.searchNodeByValue(root, 3);
    TreeNode * q = t.searchNodeByValue(root, 5);

    string str = "codeleet";
    int n = 1804289383;
    TreeNode * result = s.lowestCommonAncestor(root, p, q);
    cout<<result->val<<endl;
}