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
    vector<int> buildTreeToArray(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);

        vector<int> result;

        while(q.size() > 0) {
            TreeNode *p = q.front();
            if(p == NULL) {
            result.push_back(-1);
            q.pop();
            continue;
            }
            result.push_back(p->val);
            q.pop();

            if(p->left == NULL && p->right == NULL) continue;
            
            q.push(p->left);
            q.push(p->right);
        }
        return result;
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> result = buildTreeToArray(root);
        sort(result.begin(), result.end());
        int target = -1;
        int count = 0;
        for(int i=0;i < result.size();i++) {
            if(result[i] != -1 && target != result[i]) {
                target = result[i];
                count++;
            }

            if(count == 2) {
                return target;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    #define null -1
    vector<int> c
    {
       2,2,2
    };

    string str = "codeleet";
    TreeNode *root;
    Tree t;
    root = t.buildNode(c);
    int result = s.findSecondMinimumValue(root);
    cout<<result<<endl;
}