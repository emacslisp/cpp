#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

#define ll long long

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vector<int>> buy;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> sell;
        for(auto x: orders) {
            int price = x[0];
            int amount = x[1];
            int type = x[2];

            if(type == 0) {
                while(sell.size() > 0 && amount > 0) {
                    vector<int> y = sell.top();
                    sell.pop();
                    if(price >= y[0]) {
                        int t= min(amount, y[1]);
                        amount -=t;
                        y[1] -=t;
                        if(y[1] > 0) {
                            sell.push(y);
                        }
                    } else {
                        sell.push(y);
                        break;
                    }
                }

                if(amount > 0) {
                    x[1] = amount;
                    buy.push(x);
                }
            } else {
                while(buy.size() > 0 && amount > 0) {
                    vector<int> y = buy.top();
                    buy.pop();
                    if(y[0] >= price) {
                        int t= min(amount, y[1]);
                        amount -=t;
                        y[1] -=t;
                        if(y[1] > 0) {
                            buy.push(y);
                        }
                    } else {
                        buy.push(y);
                        break;
                    }
                }

                if(amount > 0) {
                    x[1] = amount;
                    sell.push(x);
                }
            }
        }

        long total = 0;

        while(buy.size() > 0) {
            vector<int> x = buy.top();
            buy.pop();
            total += x[1];
        }

         while(sell.size() > 0) {
            vector<int> x = sell.top();
            sell.pop();
            total += x[1];
        }

        // cout << total <<  endl;
        return total %1000000007;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{7,1000000000,1},{15,3,0},{5,999999995,0},{5,1,1}};

    string str = "codeleet";
    int n = 1804289383;
    int result = s.getNumberOfBacklogOrders(c);
    cout<<result<<endl;
}