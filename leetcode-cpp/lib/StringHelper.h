#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;

class StringHelper {
public:
    string revert(string s);
    string charToString(char c);
    bool isPalindrom(string s);
    int isNum(char *s);
    int isLetter(char *s);

    int MainEntry();
    vector<string> splitByChar(string s, char c);
};