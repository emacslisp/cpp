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

int NumberHelper::MainEntry() {
    NumberHelper n;
    cout<< n.NumberToBinary(1025) << endl;
    return 0;
}