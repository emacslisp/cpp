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
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)

class Solution {
public:
    char grid[3][3];
    bool isWin(char c) {
        // check row
        bool result = false;
        fora(i, 0 , 3) {
            bool isSame = true;
            fora(j, 0, 3) {
                if(grid[i][j]!= c) {
                    isSame = false;
                    break;
                }
            }
            if(isSame) {
                result = true;
            }
        }
        // check column
        fora(i, 0 , 3) {
            bool isSame = true;
            fora(j, 0, 3) {
                if(grid[j][i]!= c) {
                    isSame = false;
                    break;
                }
            }
            if(isSame) {
                result = true;
            }
        }
        // check dialog
        bool isSame = true;
        fora(i, 0 , 3) {
                if(grid[i][i]!= c) {
                    isSame = false;
                    break;
                }
        }
        if(isSame) {
            result = true;
        }
        // check another dialog

        isSame = true;
        fora(i, 0 , 3) {
                if(grid[2 - i][i]!= c) {
                    isSame = false;
                    break;
                }
        }
        if(isSame) {
            result = true;
        }

        return result;
    }
    string tictactoe(vector<vector<int>>& moves) {
        int index = 0;
        for(vector<int> x : moves) {
            if(index%2 == 0) {
                grid[x[0]][x[1]] = 'X';
            } else {
                grid[x[0]][x[1]] = 'O';
            }
            index++;
        }

        if(isWin('X')) {
            return "A";
        }
        
        if(isWin('O')) {
            return "B";
        }

        if(moves.size() < 9) return "Pending";
        
        return "Draw";
    }
};

int main() {
    Solution s;
    vector<vector<int> > c
    {{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};

    string str = "codeleet";
    int n = 1804289383;
    string result = s.tictactoe(c);
    cout<<result<<endl;
}