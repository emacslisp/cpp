#include "StringHelper.h"

string StringHelper::gcdOfStrings(string str1, string str2)
{
    if (str1 == str2)
        return str1;

    if (str1.size() < str2.size())
        return gcdOfStrings(str2, str1);

    size_t p = str1.find(str2);
    if (p != 0)
        return "";

    return gcdOfStrings(str1.substr(str2.size()), str2);
}

string StringHelper::toLowerStr(string s) {
    string result;
    for(char c:s) {
        result.push_back(toLower(c));
    }
    return result;
}

char StringHelper::toLower(char c) {
    if (c >= 'A' && c<='Z') {
        c = c - ('Z' - 'z');
    }
    return c;
}

string StringHelper::toUpperStr(string s) {
    string result;
    for(char c:s) {
        result.push_back(toUpper(c));
    }
    return result;
}

char StringHelper::toUpper(char c) {
    if (c >= 'a' && c<='z') {
        c = c + ('Z' - 'z');
    }
    return c;
}

vector<string> StringHelper::splitByString(string s, string delim) {
    vector<string> result;
    auto start = 0U;
    auto end = s.find(delim);

    while (end != std::string::npos)
    {
        result.push_back(s.substr(start, end - start));
        start = end + delim.length();
        end = s.find(delim, start);
    }

    result.push_back(s.substr(start, end - start));

    return result;
}

vector<string> StringHelper::splitByChar(string s, char c) {
    vector<string> result;
    string t;
    for(int i=0;i<s.size();i++) {
        if(s[i] != c)
            t.push_back(s[i]);
        else {
            result.push_back(t);
            t = "";
        }
    }
    result.push_back(t);
    return result;
}

string StringHelper::revert(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string StringHelper::charToString(char c) {
    string s;
    s.push_back(c);
    return s;
}


bool StringHelper::isPalindrom(string s)
{
    bool result = true;
    if (s.size() == 0 || s.size() == 1)
        return result;

    for (int i = 0; i <= s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
        {
            result = false;
            break;
        }
    }
    return result;
}

int StringHelper::isNum(char *s)
{
  return (*s - '0') >= 0&&(*s - '0') <= 9;
}

int StringHelper::isLetter(char *s)
{
  return ((*s - 'a') >= 0&&(*s - 'z') <= 0)
    ||((*s - 'A') >= 0&&(*s - 'Z') <= 0);
}


int StringHelper::MainEntry() {
    StringHelper s;

    cout << "================= StringHelper =====================" << endl;
    cout << s.revert("abcdef") << endl;

    string x = "I want to do  something!!1";
    vector<string> result = s.splitByChar(x, ' ');
    for(string m: result) {
        cout<<m<<endl;
    }

    cout<<"toLowerStr example:"<<endl;
    cout<<s.toLowerStr(x)<<endl;

    cout<<"toUpperStr example:"<<endl;
    cout<<s.toUpperStr(x)<<endl;

    result = s.splitByString("dababc", "ab");
    for(auto x: result)
        cout<< x << endl;

    string str1 = "ABABAB";
    string str2 = "ABAB";
    string gcdResult = s.gcdOfStrings(str1, str2);
    cout << "GCD of two string " << str1 << " " << str2 << " is : " << gcdResult << endl;
    return 0;
}