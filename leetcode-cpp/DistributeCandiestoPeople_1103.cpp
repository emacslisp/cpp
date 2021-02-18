#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int x = sqrt(2*candies + 0.25) - 0.5;

        int k = x/num_people;

        vector<int> result(num_people, 0);

        int left = candies;
        if (k>=1) {
            int sum = 0;
            for(int i=0;i<num_people;i++) {
                result[i] = k*(k-1)*num_people/2 + (i+1)*k;
                sum += result[i];
            }

            left -= sum;
        }

        for(int i=0;i<num_people;i++) {
            int t = (k*num_people + 1 + i);
            if(left >= t) {
                result[i] += t;
                left -= t;
            } else {
                result[i] += left;
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "codeleet";
    int candies = 12;
    int num_people = 4;

    vector<int> result = s.distributeCandies(candies, num_people);
    for(int x: result)
        cout<<x<<endl;
}