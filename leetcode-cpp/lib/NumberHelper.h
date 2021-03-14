#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// use Array to Simulate Queue
class NumberHelper {
public:
    string NumberToBinary(int N);
    string thousandSeparator(int n);
    int MySqrt(int x);
    int gcd(int a, int b);
    int findGCDInArray(vector<int> arr);
    int romanToInt(string s);
    string multiply(string num1, string num2);
    int stringToNumber(string num);
    int MainEntry();
};