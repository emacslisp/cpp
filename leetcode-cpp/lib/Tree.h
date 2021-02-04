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
    int TreeHeight(TreeNode *root);
    int TreeHeight(Node *root);

    TreeNode* searchNodeByValue(TreeNode *root, int x);
    void MainEntry();
};