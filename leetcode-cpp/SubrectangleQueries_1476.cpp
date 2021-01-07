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


class SubrectangleQueries {
public:
    vector<vector<int>> r;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        r = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1;i<=row2;i++) {
            for(int j=col1;j<=col2;j++) {
                r[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return r[row][col];
    }
};

int main() {
    
    vector<vector<int>> c
    {
       {1, 2, 1},
       {4, 3, 4},
       {3, 2, 1},
       {1, 1, 1}
    };
    SubrectangleQueries s(c);

    string str = "codeleet";
    int result = s.getValue(0,2);
    cout<<result<<endl;
    s.updateSubrectangle(0,0,3,2,5);
    result = s.getValue(0,2);
    cout<<result<<endl;
    result = s.getValue(3,1);
    cout<<result<<endl;
    s.updateSubrectangle(3,0,3,2,10);
    result = s.getValue(3,1);
    cout<<result<<endl;
    result = s.getValue(0,2);
    cout<<result<<endl;
}