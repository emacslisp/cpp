#include "Tree.h"

Tree::Tree() {

}

Tree::~Tree() {
    
}

TreeNode * Tree::buildNode(vector<int> a) {
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