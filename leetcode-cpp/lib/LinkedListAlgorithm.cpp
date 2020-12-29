#include "LinkedListAlgorithm.h"

ListNode* LinkedListAlgorithm::revertList(ListNode* head) {
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

ListNode* LinkedListAlgorithm::arrayToList(vector<int> c) {
    ListNode* head = new ListNode(c[0]);
    	ListNode* p = head;
    	for(int i=1;i<c.size();i++) {
    		p->next = new ListNode(c[i]);
    		p = p->next;
    	}
    	
    	return head;
}