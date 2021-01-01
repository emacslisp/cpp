#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

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


TreeNode * buildNode(vector<int> a) {
    queue<TreeNode *> q;
    TreeNode *head = new TreeNode(a[0]);
    q.push(head);
    int count = 0;
    TreeNode *cur;
    for (int i = 1; i < a.size(); i++) {
        TreeNode *node = NULL;
        if (a[i] != -1)
            node = new TreeNode(a[i]);
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
        if(node != NULL){
          q.push(node);
        }
    }
    return head;
}

int main() {
    Solution s;
    TreeNode* root;
    vector<int> a {
        1,2,3, 4
    };

    root = buildNode(a);

    string result = s.tree2str(root);
    cout<<result<<endl;
}