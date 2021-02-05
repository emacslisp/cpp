#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include "lib/Tree.h"

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    
    void dfs(TreeNode * root1, vector<int> &r1) {
        if(root1 == NULL) return;
        if(root1->left == NULL && root1->right == NULL) {
            r1.push_back(root1->val);
            return;
        }
        
        dfs(root1->left, r1);
        dfs(root1->right, r1);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1, r2;
        dfs(root1, r1);
        dfs(root2, r2);

        if (r1.size() == r2.size()) {
            for(int i=0;i<r1.size();i++) {
                cout << r1[i] << " " << r2[i] << endl;
                if(r1[i] != r2[i]) {
                    return false;
                }
            }
            return true;
        }

        return false;
    }
};

int main() {
    Solution s;
    Tree t;

    #define null -1
    vector<int> c1
    {
       1,2
    };
    vector<int> c2
    {
       2,2
    };

    string str = "codeleet";

    TreeNode* root1 = t.buildNode(c1);
    TreeNode* root2 = t.buildNode(c2);

    bool result = s.leafSimilar(root1, root2);
    cout<<result<<endl;
}