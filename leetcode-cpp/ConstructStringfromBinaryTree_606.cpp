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
    string tree2str(TreeNode* t) {
        if(t == NULL) return "";
        string result;
        result += (to_string(t->val));
        string l = tree2str(t->left);
        string r = tree2str(t->right);
        if (!l.empty() && !r.empty()) {
            result += ("(" + l + ")");
            result += ("(" + r + ")");
        }

        if(!l.empty() && r.empty()) {
            result += ("(" + l + ")");
        }

        if (l.empty() && !r.empty()) {
            result += ("()(" + r + ")");
        }

        return result;
    }
};




int main() {
    Solution s;
    TreeNode* root;
    vector<int> a {
        1,2,3, 4
    };

    Tree t;
    root = t.buildNode(a);

    string result = s.tree2str(root);
    cout<<result<<endl;
}