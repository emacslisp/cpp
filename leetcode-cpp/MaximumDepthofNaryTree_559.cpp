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
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int result = 0;

        for(Node * p : root->children) {
            int h = maxDepth(p);
            if(result < h) result = h;
        }

        return result + 1;
    }
};

Node * buildTree(vector<int> c) {
    queue<Node *> q;
    Node * head = new Node(c[0]);
    q.push(head);

    int index = 2;
    while(q.size() > 0 && index < c.size()) {
        Node * root = q.front();
        q.pop();
        int i= index;
        for(;i<c.size();i++) {
            if(c[i] == -1) {
                index = i+1;
                break;
            }
            Node* newNode = new Node(c[i]);
            root->children.push_back(newNode);
            q.push(newNode);
        }
        index = i+1;
    }
    return head;
}

int main() {
    Solution s;
    #define null -1
    vector<int> c
    {
       1,null,3,2,4,null,5,6
    };

    Node *root;
    root = buildTree(c);

    int result = s.maxDepth(root);
    cout<<result<<endl;
}