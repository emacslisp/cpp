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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a;
        stack<int> b;
        stack<int> c;
        ListNode* p = l1;

        while(p!= NULL) {
            a.push(p->val);
            p = p->next;
        }
        p = l2;
        while(p!= NULL) {
            b.push(p->val);
            p = p->next;
        }
        int carry = 0;
        while(a.size() > 0 && b.size() > 0) {
            int ta = a.top();
            int tb = b.top();

            int tc = ta + tb + carry;
            c.push(tc%10);
            carry = tc/10;

            a.pop();
            b.pop();
        }

        while(a.size() > 0) {
            int ta = a.top();
            int tc = ta+carry;
            c.push(tc%10);
            carry = tc/10;
            a.pop();
        }

        while(b.size() > 0) {
            int tb = b.top();
            int tc = tb+carry;
            c.push(tc%10);
            carry = tc/10;
            b.pop();
        }

        if(carry>0) {
            c.push(carry);
        }

        ListNode* head = new ListNode(c.top());
        c.pop();
        p = head;
        while(c.size() > 0) {
            p->next = new ListNode(c.top());
            c.pop();
            p = p->next;
        }
        return head;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
        5
    };

    vector<int> c1
    {
       5
    };

    LinkedListAlgorithm lla;

    ListNode *na = lla.arrayToList(c);
    ListNode *nb = lla.arrayToList(c1);

    string str = "codeleet";
    int n = 1804289383;
    ListNode* result = s.addTwoNumbers(na, nb);
    lla.printListNode(result);
}