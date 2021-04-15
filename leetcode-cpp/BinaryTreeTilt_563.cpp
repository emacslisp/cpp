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
    int sum(TreeNode *root, vector<int> &v) {
        if(root == NULL) return 0;
        int a1 = sum(root->left, v) + (root->left != NULL? root->left->val : 0);
        int a2 = sum(root->right, v) + (root->right != NULL? root->right->val : 0);
        v.push_back(abs(a1-a2));
        return a1+a2;
    }
    int findTilt(TreeNode* root) {
        vector<int> v;
        sum(root, v);

        int result = 0;
        for(int x: v) {
            // cout << x << endl;
            result += x;
        }
        return result;
    }
};

int main() {
    Solution s;
    #define null -1
    vector<int> c
    {
       21,7,14,1,1,2,2,3,3
    };

    Tree t;
    TreeNode* root = t.buildNode(c);
    string str = "codeleet";
    int n = 1804289383;
    int result = s.findTilt(root);
    cout<<result<<endl;
}