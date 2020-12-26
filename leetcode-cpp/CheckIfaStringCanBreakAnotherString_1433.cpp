#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<char> c1;
        vector<char> c2;

        for(char c: s1){
            c1.push_back(c);
        }

        for(char c: s2){
            c2.push_back(c);
        }

        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());

        bool result = true;
        for(int i=0;i<s1.size();i++)
            if (c1[i] > c2[i]) {
                vector<char> temp = c1;
                c1 = c2;
                c2 = temp;
                break;
            }
        
        for(int i=0;i<s1.size();i++) {
            if (c1[i] <= c2[i]) {

            } else {
                result = false;
                break;
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    string str = "bxfowqvnrhuzwqohquamvszkvunb";
    string str2 = "xjegbjccjjxfnsiearbsgsofywtq";

    bool result = s.checkIfCanBreak(str, str2);
    cout<<result<<endl;
}