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
class tobj {
public:
    int val;
    int index; 
    tobj(int val, int index) {
        this->val = val;
        this->index = index;
    }
};

bool cmp(tobj t1, tobj t2) {
    return t1.val < t2.val;
}
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *p = head;
        int l = 0;
        
        while(p) {
            l++;
            p = p->next;
        }

        vector<int> r(l, 0);

        stack<pair<int,int>> st;

        p = head;
        int index = 0;
        while(p) {
            while(st.size() > 0  && p->val > st.top().first) {
                r[st.top().second] = p->val;
                st.pop();
            }
            st.push(make_pair(p->val, index++));
            p=p->next;
        }

        return r;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,7,5,1,9,2,5,1
    };

    string str = "codeleet";
    int n = 1804289383;

    LinkedListAlgorithm lla;
    ListNode* head = lla.arrayToList(c);
    vector<int> result = s.nextLargerNodes(head);
    for(int x: result)
    cout<<x<<endl;
}