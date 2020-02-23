/*
 * ReverseLinkedList92.cpp
 *
 *  Created on: 21 Dec 2019
 *      Author: wudi
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class ReverseLinkedList92 {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* prev = NULL;
		ListNode* current = head;
		ListNode* next = NULL;

		ListNode* startPrev = NULL;
		ListNode* start = NULL;
		ListNode* end = NULL;

		int i =1;

		while(i<m) {

			prev = current;
			current = current->next;
			i++;
		}

		start = current;
		startPrev = prev;

		while(i<=n) {
			next = current->next;
			current->next = prev;
			prev = current;
			current=next;
			i++;
		}

		end = prev;
		start->next = current;

		if(startPrev != NULL)
			startPrev->next = end;

		if(m ==1)
			return end;

		return head;
	}

	void main() {
		int array[] = {1,2,3,4,5};
		ListNode* header = new ListNode(array[0]);
		ListNode* current = header;
		for(int i=1;i<sizeof(array)/sizeof(array[0]);i++) {
			ListNode* p = new ListNode(array[i]);
			current->next = p;
			current = p;
		}
		int m = 2;
		int n = 5;
		ListNode* result = reverseBetween(header, m, n);
		current = result;
		while(current != NULL) {
			cout << current->val << " " << endl;
			current = current->next;
		}
	}
};

