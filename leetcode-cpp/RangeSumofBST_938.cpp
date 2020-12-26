#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL) return 0;

        int result = 0;
        if(root -> val >= low && root->val <= high) {
            result += root->val;
        }
        result += rangeSumBST(root->left, low, high);
        result += rangeSumBST(root->right, low, high);
        return result;
    }
};

TreeNode * buildNode(vector<int> a) {
    queue<TreeNode *> q;
    TreeNode *head = new TreeNode(a[0]);
    q.push(head);
    int count = 0;
    TreeNode *cur;
    for (int i = 1; i < a.size(); i++) {
        TreeNode *node = new TreeNode(a[i]);
        if(count == 0){
           cur = q.front();  
           q.pop();         
        }
        if(count==0){
          count++;
          cur -> left = node;
        }else {
          count = 0;
          cur -> right = node;
        }
        if(a[i] != -1){
          q.push(node);
        }
    }
    return head;
}

int main() {
    Solution s;
    TreeNode* root;
    vector<int> a {
        10,5,15,3,7,13,18,1,-1,6
    };

    root = buildNode(a);

    int low = 6;
    int high = 10;

    int result = s.rangeSumBST(root, low, high);
    cout<<result<<endl;
}