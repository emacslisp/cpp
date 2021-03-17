#include<vector>
#include<iostream>
#include "ListNode.h"
using namespace std;

class LinkedListAlgorithm {
    public:
        ListNode* revertList(ListNode* head);
        ListNode* arrayToList(vector<int> c);
        vector<int> listToArray(ListNode *head);
};