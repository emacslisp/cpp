#include "StringHelper.h"

string StringHelper::revert(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int StringHelper::MainEntry() {
    StringHelper s;
    cout << s.revert("abcdef") << endl;
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
