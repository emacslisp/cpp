#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include "./lib/LinkedListAlgorithm.h"

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        int count = 0;
        int count1 = 0;
        ListNode* p = head;
        ListNode* p1;
        ListNode* p2;
        ListNode* p3;
        ListNode* p4;
        ListNode* p5;
        while(p!=NULL) {
            count++;
            p = p->next;
        }

        p = head;
        while(p!=NULL) {
            if(count1 == (k-1)) {
                p1 = p;
            }

            if(count1 == (count - k)) {
                p3 = p;
            }
            count1++;
            p = p->next;
        }

        int t = p1->val;
        p1->val = p3->val;
        p3->val = t;
        return head;
    }
};

ListNode* arrayToList(vector<int> c) {
    ListNode* head = new ListNode(c[0]);
    	ListNode* p = head;
    	for(int i=1;i<c.size();i++) {
    		p->next = new ListNode(c[i]);
    		p = p->next;
    	}
    	
    	return head;
}

int main() {
    Solution s;
    vector<int> c
    {
       1,2,3
    };

    ListNode* head = arrayToList(c);
    int k = 2;

    ListNode* result = s.swapNodes(head, k);
    while(result != NULL) {
        cout << result -> val << endl;
        result = result->next;
    }
}