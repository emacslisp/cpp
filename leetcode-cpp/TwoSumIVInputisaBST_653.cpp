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
    void foo(TreeNode* root, map<int, int> &m) {
        if(root == NULL) return;
        m[root->val]++;
        foo(root->left, m);
        foo(root->right, m);
    }

    bool findTarget(TreeNode* root, int k) {
        map<int, int> m;
        foo(root, m);

        for(auto x: m) {
            int t = k-x.first;
            if(t == x.first ) {
                if(m[t]>=2) {
                    return true;
                } else {
                    continue;
                }
            }

            if(m.count(k-x.first) == 1) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    #define null 1
    vector<int> c
    {
       1
    };
    Tree t;

    TreeNode *root = t.buildNode(c);
    int k = 2;
    string str = "codeleet";

    bool result = s.findTarget(root, k);
    cout<<result<<endl;
}