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

class TNode {
public:
    TreeNode *t;
    int level;
    TNode(TreeNode *root, int level) {
        t = root;
        this->level = level;
    }
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        map<int, vector<TNode>> m;

        queue<TNode> q;
        q.push(TNode(root, 1));

        int maxLevel = 0;
        while(q.size() > 0) {
            TNode p = q.front();
            q.pop();
            if(maxLevel < p.level) {
                maxLevel = p.level;
            }

            if(m.count(p.level) == 0) {
                m[p.level] = vector<TNode>();
            } 
            m[p.level].push_back(p);

            if(p.t->left != NULL) {
                q.push(TNode(p.t->left, p.level + 1));
            }

            if(p.t->right != NULL) {
                q.push(TNode(p.t->right, p.level + 1));
            }
        }

        vector<double> result;
        for(int i=1;i<=maxLevel;i++) {
            double sum = 0;
            for(TNode x : m[i]) {
                sum += x.t->val;
            }
            result.push_back(sum/(double)m[i].size());
        }

        return result;
    }
};

int main() {
    Solution s;
    Tree t;
    vector<int> c
    {
       3, 9 , 20, -1, -1, 15, 7
    };

    TreeNode * root = t.buildNode(c);

    vector<double> result = s.averageOfLevels(root);

    for(double x: result)
        cout<<x<<endl;
}