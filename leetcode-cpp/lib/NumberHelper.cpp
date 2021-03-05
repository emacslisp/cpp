#include "NumberHelper.h"

string NumberHelper::multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0") return "0";
    int m = num1.size();
    int n = num2.size();
    string result(m+n, '0');
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int multiFlag = 0;
    int addFlag = 0;

    for(int i=0;i<n;i++) {
        multiFlag = 0;
        addFlag = 0;
        for(int j=0;j<m;j++) {
            int t1 = (num1[j] - '0') * (num2[i] - '0') + multiFlag;
            multiFlag = t1/10;
            t1 %= 10;
            int t2 = (result[i+j] - '0') + t1 + addFlag;
            addFlag = t2/10;
            result[i+j] = t2%10 + '0';
        }
        result[i+m] += multiFlag + addFlag;
    }

    reverse(result.begin(), result.end());

    if(result[0] == '0') result.erase(result.begin());
    return result;
}

string NumberHelper::NumberToBinary(int N) {
    int p = N;
    string output;
    while(p>0) {
        output.push_back((char)(p%2 + '0'));
        p = p/2;   
    }
    reverse(output.begin(), output.end());
    return output;
}

string NumberHelper::thousandSeparator(int n) {
        string s = to_string(n);
        if(n<1000) return s;
        reverse(s.begin(), s.end());
        string result;
        int counter = 0;
        for(int i=0;i<s.size();i++) {
            result.push_back(s[i]);
            counter++;
            if(counter == 3 && i != s.size() - 1) {
                result.push_back(',');
                counter = 0;
            }
        }
        reverse(result.begin(), result.end());
        return result;
}

int NumberHelper::MySqrt(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;

    int l = 1, w = x, res = 0;

    int mid;
    while (l < w)
    {
        mid = (l + w) / 2;

        if (mid > x / mid)
        {
            w = mid - 1;
        }
        else
        {
            //very important: mid * mid < x and x< (mid + 1) * (mide + 1), then mid is answer
            if (mid + 1 > x / (mid + 1))
                return mid;

            l = mid + 1;

            if (l == x / l)
                return l;
        }
    }

    return w;
}

int NumberHelper::gcd(int a, int b) 
{ 
        if (a == 0) 
            return b; 
        return gcd(b % a, a); 
} 
int NumberHelper::findGCDInArray(vector<int> arr) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < arr.size(); i++) 
        result = gcd(arr[i], result); 

    return result; 
} 

int NumberHelper::romanToInt(string s) {
    reverse(s.begin(), s.end());

        vector<char> c {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        vector<int> ic {1, 5, 10, 50, 100, 500, 1000};
        map<char, int> m;

        for(int i=0;i<c.size();i++) m[c[i]] = ic[i];

        int count = 0;
        int result = 0;
        while(true) {

            if(count + 1 < s.size() && m[s[count + 1]] < m[s[count]]) {
                result += (m[s[count]] - m[s[count+1]]);
                count+=2;
            } 
            else {
                result += m[s[count]];
                count++;
            }

            if(count >= s.size()) {
                break;
            }
        }

        return result;
}

int NumberHelper::MainEntry() {
    NumberHelper n;
    cout << "================= NumberHelper =====================" << endl;
    cout << "NumberHelper.NumberToBinary convert number to Binary: " << endl;
    cout<< n.NumberToBinary(1025) << endl;
    cout << "NumberHelper.thousandSeparator - adding separator for thousand: " << endl;
    cout << n.thousandSeparator(123456789) << endl;

    cout << n.MySqrt(1000) << endl;

    string s = "MCMXCIV";
    cout << "roman to int: " << s << " result: " << n.romanToInt(s)  << endl;

    cout << "123456789 * 12 = " << n.multiply("923456789", "12") << endl;
    return 0;
}