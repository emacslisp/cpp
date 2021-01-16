#include "Tree.h"

Tree::Tree()
{
}

Tree::~Tree()
{
}

Node *Tree::buildNaryTreeNode(vector<int> c)
{
  queue<Node *> q;
  Node *head = new Node(c[0]);
  q.push(head);

  int index = 2;
  while (q.size() > 0 && index < c.size())
  {
    Node *root = q.front();
    q.pop();
    int i = index;
    for (; i < c.size(); i++)
    {
      if (c[i] == -1)
      {
        index = i + 1;
        break;
      }
      Node *newNode = new Node(c[i]);
      root->children.push_back(newNode);
      q.push(newNode);
    }
    index = i + 1;
  }
  return head;
}

int Tree::TreeHeight(TreeNode* root) {
  if(root == NULL) return 0;
  int left = TreeHeight(root->left);
  int right = TreeHeight(root->right);

  if(left > right) return left + 1;

  return right + 1;
}

int Tree::TreeHeight(Node* root) {
  if(root == NULL) return 0;
  int max = 0;

  for(Node* p : root->children) {
    int h = TreeHeight(p);
    if(max < h) max = h;
  }

  return max + 1;
}

TreeNode *Tree::buildNode(vector<int> a)
{
  queue<TreeNode *> q;
  TreeNode *head = new TreeNode(a[0]);
  q.push(head);
  int count = 0;
  TreeNode *cur;
  for (int i = 1; i < a.size(); i++)
  {
    TreeNode *node = NULL;
    if (a[i] != -1)
      node = new TreeNode(a[i]);
    if (count == 0)
    {
      cur = q.front();
      q.pop();
    }
    if (count == 0)
    {
      count++;
      cur->left = node;
    }
    else
    {
      count = 0;
      cur->right = node;
    }
    if (node != NULL)
    {
      q.push(node);
    }
  }
  return head;
}

void Tree::MainEntry() {
  Tree t;

  #define null -1
    vector<int> c
    {
       1,null,3,2,4,null,5,6
    };

    Node *root;
    root = t.buildNaryTreeNode(c);

    int result = t.TreeHeight(root);
    cout<<result<<endl;
}