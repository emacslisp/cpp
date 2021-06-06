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
    vector<string> splitByString(string s, string delim);
    char toLower(char c);
    string toLowerStr(string s);

    char toUpper(char c);
    string toUpperStr(string s);
    string gcdOfStrings(string str1, string str2);
    bool isSubstring(string str1, string str2);
};