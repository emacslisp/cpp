#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while (true)
        {
            if ((t - q.front()) > 3000)
            {
                q.pop();
            }
            else
            {
                break;
            }
        }

        return q.size();
    }
};

int main() {
    RecentCounter s;
    vector<int> c {
        642, 1849, 4921, 5936, 5957
    };
    for(int x: c) {
        int result = s.ping(x);
        cout << result << endl; 
    }
}