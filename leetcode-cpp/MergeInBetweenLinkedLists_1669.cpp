#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include "./lib/LinkedListAlgorithm.h"
using namespace std;

#define ll long long

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int counter = 0;

        ListNode *p1, *p2;
        ListNode *t = list1;
        while(counter <= b) {
            if(counter == a-1) {
                p1 = t;
            }

            if(counter == b) {
                p2 = t;
            }
            t = t->next;
            counter++;
        }

        p1->next = list2;
        while(list2->next != NULL) {
            list2 = list2->next;
        }
        list2->next = p2->next;

        return list1;
    }
};

int main() {
    Solution s;
    vector<int> list1
    {
       0,1,2,3,4,5,6
    };

    vector<int> list2
    {
       1000000,1000001,1000002,1000003,1000004
    };

    LinkedListAlgorithm lla;

    ListNode* l1 = lla.arrayToList(list1);
    ListNode* l2 = lla.arrayToList(list2);

    int a, b;
    a = 2;
    b = 5;
    ListNode* result = s.mergeInBetween(l1, a, b, l2);
    vector<int> t = lla.listToArray(result);
    for(int x: t)
    cout<<x<<endl;
}