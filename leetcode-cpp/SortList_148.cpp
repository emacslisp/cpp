#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include "lib/LinkedListAlgorithm.h"
using namespace std;

#define ll long long
#define ld long double
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9+7;
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))


class Solution {
public:
vector<int> listToArray(ListNode *head)
{
	vector<int> result;
	ListNode *p = head;
	while(p != NULL) {
		result.push_back(p->val);
		p = p->next;
	}
	return result;
}

ListNode *arrayToList(vector<int> c)
{
	ListNode *head = new ListNode(c[0]);
	ListNode *p = head;
	for (int i = 1; i < c.size(); i++)
	{
		p->next = new ListNode(c[i]);
		p = p->next;
	}

	return head;
}
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        vector<int> v = listToArray(head);
        sort(v.begin(), v.end());
        return arrayToList(v);
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4, 2, 1, 3
    };

    string str = "codeleet";
    int n = 1804289383;
    LinkedListAlgorithm l;
    ListNode* head = l.arrayToList(c);
    ListNode* result = s.sortList(head);
    l.printListNode(result);
}