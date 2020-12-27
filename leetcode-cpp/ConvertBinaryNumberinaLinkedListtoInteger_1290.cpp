#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        head = revertList(head);

        int result = 0;
        int bin = 1;
        ListNode * p = head;
        while(p!=NULL) {
            result += p->val*bin;
            bin *=2;
            p=p->next;
        }

        return result;
    }

    ListNode* revertList(ListNode* head) {
    	if(head == NULL) return NULL;
        if(head -> next == NULL) return head;
        
    	ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = NULL;
        
        while(current != NULL) {
        	next = current -> next;
        	current->next = prev;
        	prev = current;
        	current = next;
        }

        return prev;
    }
};

ListNode* initListNode(vector<int> c) {
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
       1,0,0,1,0,0,1,1,1,0,0,0,0,0,0
    };

    ListNode* head = initListNode(c);

    int result = s.getDecimalValue(head);
    cout<<result<<endl;
}