#include <vector>
#include <iostream>
#include <queue>
#include "TreeNode.h"
#include "Node.h"

using namespace std;

class Tree
{
public:
    Tree();
    ~Tree();
    TreeNode* buildNode(vector<int> a);
    Node* buildNaryTreeNode(vector<int> c);
    vector<int> buildTreeToArray(TreeNode* root);

    TreeNode* buildBalancedTreeFromArray(vector<int> a);
    int TreeHeight(TreeNode *root);
    int TreeHeight(Node *root);

    TreeNode* searchNodeByValue(TreeNode *root, int x);
    void MainEntry();
private:
    TreeNode* buildBalancedTree(vector<int>& nums, int start, int end);
};