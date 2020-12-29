#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        for(int x: students) {
            q.push(x);
        }

        int index = 0;
        int noAccept = 0;
        while(true) {
            int x = q.front();
            if (sandwiches[index] == x) {
                q.pop();
                index++;
                noAccept = 0;
            } else {
                q.pop();
                q.push(x);
                noAccept++;
                if (noAccept == q.size()) return q.size();
            }

            if(q.size() == 0) return 0;
        }
    }
};

int main() {
    Solution s;
    vector<int> students
    {
       1,1,1,0,0,1
    };

    vector<int> sandwiches
    {
       1,0,0,0,1,1
    };

    int result = s.countStudents(students, sandwiches);
    cout<<result<<endl;
}