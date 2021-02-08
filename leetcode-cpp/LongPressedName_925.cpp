#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        /*
        int p1 = 0, p2 = 0;
        while (p1 < name.size() && p2 < typed.size()) {
            if (name[p1] != typed[p2]) return false;
            int c1 = 1, c2 = 1;
            p1++, p2++;
            while (p1 < name.size() && name[p1] == name[p1-1]) c1++, p1++;
            while (p2 < typed.size() && typed[p2] == typed[p2-1]) c2++, p2++;
            if (c1 > c2) return false;
        }
        return (p1 == name.size() && p2 == typed.size());
        */
        vector<char> vc(name.size(),'.');
        vector<int> c(name.size(),0);

        vector<char> vc2(typed.size(),'.');
        vector<int> c2(typed.size(),0);
        
        char currentChar = ' ';
        int count = -1;
        for (int i=0;i<name.size();i++) {
            if(currentChar != name[i]) {
                count++;
                vc[count] = name[i];
                currentChar = name[i];
                c[count] = 1;
            } else {
                c[count]++;
            }
        }
        
        currentChar = ' ';
        int count2 = -1;
        for (int i=0;i<typed.size();i++) {
            if(currentChar != typed[i]) {
                count2++;
                vc2[count2] = typed[i];
                currentChar = typed[i];
                c2[count2] = 1;
            } else {
                c2[count2]++;
            }
        }

        if(count != count2) return false;

        for(int i=0;i<=count;i++) {
            if(vc[i] != vc2[i]) return false;
            if(c[i] > c2[i]) return false;
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string name = "rick";
    string typed = "krick";
    bool result = s.isLongPressedName(name, typed);
    cout<< (result? "true" : "false") << endl;
}