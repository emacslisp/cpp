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

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node *root)
    {
        vector<int> result;
        if (root== NULL) return result;

        if (root->children.size() > 0)
        {
            for (Node *x : root->children)
            {
                vector<int> t = postorder(x);
                for (int m : t)
                {
                    result.push_back(m);
                }
            }
            result.push_back(root->val);
        }
        else
        {
            result.push_back(root->val);
        }
        return result;
    }
};

int main() {
    Solution s;
    Node* root = new Node(1);
    Node* n1 = new Node(3);
    Node* n2 = new Node(2);
    Node* n3 = new Node(4);
    root->children.push_back(n1);
    root->children.push_back(n2);
    root->children.push_back(n3);

    Node* n4 = new Node(5);
    Node* n5 = new Node(6);
    n1->children.push_back(n4);
    n1->children.push_back(n5);

    vector<int> result = s.postorder(root);

    for(int x: result)
    cout<<x<<endl;
}