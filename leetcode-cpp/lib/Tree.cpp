#include "Tree.h"

Tree::Tree()
{
}

Tree::~Tree()
{
}

int Tree::longestPathInTree(TreeNode *root) {
        if(root == NULL) return 0;
        int l = TreeHeight(root->left);
        int r = TreeHeight(root->right);
        int d = l+r;
        return max(d, 
                   max(longestPathInTree(root->left), 
                       longestPathInTree(root->right)));

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

  return 1 + max(left, right);
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

TreeNode* Tree::searchNodeByValue(TreeNode* root, int x) {
  if(root == NULL) return NULL;
  if(root->val == x) return root;

  TreeNode* n1 = Tree::searchNodeByValue(root->left, x);
  TreeNode* n2 = Tree::searchNodeByValue(root->right, x);

  if(n1 != NULL) return n1;
  if(n2 != NULL) return n2;
  return NULL;
}

vector<int> Tree::buildTreeToArray(TreeNode *root) {
  queue<TreeNode *> q;
  q.push(root);

  vector<int> result;

  while(q.size() > 0) {
    TreeNode *p = q.front();
    if(p == NULL) {
      result.push_back(-1);
      q.pop();
      continue;
    }
    result.push_back(p->val);
    q.pop();

    if(p->left == NULL && p->right == NULL) continue;
    
      q.push(p->left);
      q.push(p->right);
  }
  return result;
}

TreeNode* Tree::buildBalancedTree(vector<int>& nums, int start, int end) {
    if (start > end) {
        return NULL;
    }
    
    int mid = start + (end-start)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildBalancedTree(nums, start, mid-1);
    root->right = buildBalancedTree(nums, mid+1, end);
    return root;
}

TreeNode* Tree::buildBalancedTreeFromArray(vector<int> a) {
  sort(a.begin(), a.end());
  return this -> buildBalancedTree(a, 0, a.size() - 1);
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
  cout << "================= Tree =====================" << endl;
  #define null -1
    vector<int> c
    {
       1,null,3,2,4,null,5,6
    };

    Node *root;
    root = t.buildNaryTreeNode(c);

    TreeNode* r = t.buildNode(c);

    int result = t.longestPathInTree(r);
    cout << "longest path in binary tree is: " << result << endl;

    vector<int> output = t.buildTreeToArray(r);

    for(int x: output) {
      cout << x << " ";
    }
    cout << endl;

    result = t.TreeHeight(root);
    cout<<result<<endl;

    vector<int> cb {
      1,2,3,4,5,6,7
    };

    r = t.buildBalancedTreeFromArray(cb);
    output = t.buildTreeToArray(r);

    for(int x: output) {
      cout << x << " ";
    }
    cout << endl;
}