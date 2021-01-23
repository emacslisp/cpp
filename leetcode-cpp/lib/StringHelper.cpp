#include "StringHelper.h"

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

int StringHelper::MainEntry() {
    StringHelper s;
    cout << s.revert("abcdef") << endl;

    string x = "I want to do something!!1";
    vector<string> result = s.splitByChar(x, ' ');
    for(string m: result) {
        cout<<m<<endl;
    }
    return 0;
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
