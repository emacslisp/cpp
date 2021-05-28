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
#define ld long double
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9+7;
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))


class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    SeatManager(int n) {
        for(int i=1;i<=n;i++) {
            q.push(i);
        }    
    }
    
    int reserve() {
        int t = q.top();
        q.pop();
        return t;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};

int main() {
    SeatManager *s = new SeatManager(5);
    int result = s -> reserve();
    cout << result << endl;

    result = s -> reserve();
    cout << result << endl;

    result = s -> reserve();
    cout << result << endl;

    s->unreserve(2);

    result = s -> reserve();
    cout << result << endl;
}