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
    int h;
    TreeNode* searchNodeByValue(TreeNode* root, TreeNode* parent, int x, int height) {
    if(root == NULL) return NULL;
    if(root->val == x) {
        h = height;
        return parent;
    }

    TreeNode* n1 = searchNodeByValue(root->left, root, x, height+1);
    TreeNode* n2 = searchNodeByValue(root->right, root, x, height+1);

    if(n1 != NULL) return n1;
    if(n2 != NULL) return n2;
    return NULL;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* p1 = searchNodeByValue(root, NULL, x, 1);
        int h1 = h;
         TreeNode* p2 = searchNodeByValue(root, NULL, y, 1);
         int h2 =h;

         if(h1 == h2 && p1 != p2) {
             return true;
         }
         return false;
    }
};

int main() {
    Solution s;
    #define null -1
    vector<int> c
    {
       1,2,3,null,4,null,5
    };

    int x = 4;
    int y = 5;
    string str = "codeleet";
    int n = 1804289383;
    Tree t;
    TreeNode* root = t.buildNode(c);
    bool result = s.isCousins(root,x,y);
    cout<<result<<endl;
}