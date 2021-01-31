#include "NumberHelper.h"

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

int NumberHelper::MainEntry() {
    NumberHelper n;
    cout<< n.NumberToBinary(1025) << endl;
    cout << n.thousandSeparator(123456789) << endl;
    return 0;
}