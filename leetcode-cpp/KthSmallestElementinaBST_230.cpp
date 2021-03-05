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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result = buildTreeToArray(root);
        sort(result.begin(), result.end());
        int target = -1;
        int count = 0;
        for(int i=0;i < result.size();i++) {
            if(result[i] != -1 && target != result[i]) {
                target = result[i];
                count++;
            }

            if(count == k) {
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
       5,3,6,2,4,null,null,1
    };

    Tree t;
    TreeNode *root = t.buildNode(c);
    string str = "codeleet";
    int k = 3;
    int result = s.kthSmallest(root, k);
    cout<<result<<endl;
}