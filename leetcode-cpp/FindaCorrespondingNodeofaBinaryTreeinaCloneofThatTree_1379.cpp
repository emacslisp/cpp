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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL && cloned == NULL) return NULL;
       if(original == target) return cloned;

        TreeNode* n1 = getTargetCopy(original->left, cloned->left, target);
        TreeNode* n2 = getTargetCopy(original->right, cloned->right, target);

        if(n1 != NULL) return n1;
        return n2;
    }
};

int main() {
    Solution s;
    Tree t;
    #define null -1
    vector<int> c
    {
       7,4,3,null,null,6,19
    };

    TreeNode *original = t.buildNode(c);
    TreeNode *cloned = t.buildNode(c);

    TreeNode *target = t.searchNodeByValue(original, 3);
    std::cout<<target -> val<<endl;

    TreeNode* result = s.getTargetCopy(original, cloned, target);

    std::cout<<result -> val<<endl;
}