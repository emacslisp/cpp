#include "ArrayHelper.h"

vector<int> ArrayHelper::revert(vector<int> c) {
    /*vector<int> result;
    for(int i=c.size()-1;i>=0;i--) {
        result.push_back(c[i]);
    }*/
    reverse(c.begin(), c.end());
    return c;
}