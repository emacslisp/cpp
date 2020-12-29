#include "StringHelper.h"

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