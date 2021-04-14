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
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)

class Solution {
public:
    void dfs(TreeNode* root, int sum, vector<int> &v, int &count) {
        if(root == NULL) return;
        v.push_back(root->val);
        
        dfs(root->left, sum, v, count);
        dfs(root->right, sum, v, count);

        int cursum=0;
        for(int j=v.size()-1;j>=0;j--)
        {
            cursum+=v[j];
           if(cursum==sum) count++;
        }
        v.pop_back();
    }

    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        vector<int> v; int count=0;
        dfs(root,sum,v,count);
       return count;
    }
};

int main() {
    Solution s;
    #define null -1
    vector<int> c
    {
       10,5,-3,3,2,null,11,3,-2,null,1
    };

    Tree t;
    TreeNode *root = t.buildNode(c);
    string str = "codeleet";
    int n = 1804289383;
    int sum = 8;
    int result = s.pathSum(root, sum);
    cout<<result<<endl;
}