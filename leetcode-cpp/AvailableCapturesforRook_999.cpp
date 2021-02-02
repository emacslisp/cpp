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


class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rx, ry;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(board[i][j] != '.') {
                    if(board[i][j] == 'R') {
                        rx = i;
                        ry = j;
                        break;
                    }
                }
            }
        }
        int counter = 0;
        for(int i=rx - 1;i>=0;i--) {
            if(board[i][ry] != '.' ) {
                if(board[i][ry] >= 'a' && board[i][ry] <= 'z') {
                    counter++;
                }
                break;
            }
        }

        for(int i=rx + 1;i < board[ry].size();i++) {
            if(board[i][ry] != '.' ) {
                if(board[i][ry] >= 'a' && board[i][ry] <= 'z') {
                    counter++;
                }
                break;
            }
        }

        for(int i=ry - 1;i>=0;i--) {
            if(board[rx][i] != '.' ) {
                if(board[rx][i] >= 'a' && board[rx][i] <= 'z') {
                    counter++;
                }
                break;
            }
        }

        for(int i=ry + 1;i < board.size();i++) {
            if(board[rx][i] != '.' ) {
                if(board[rx][i] >= 'a' && board[rx][i] <= 'z') {
                    counter++;
                }
                break;
            }   
        }
        
        return counter;
    }
};

int main() {
    Solution s;
    vector<vector<char>> c
    {
        // {{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','R','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'}}
        {'.','.','.','.','.','.','.','.'},
{'.','.','.','p','.','.','.','.'},
{'.','.','.','R','.','.','.','p'},
{'.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.'},
{'.','.','.','p','.','.','.','.'},
{'.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.'}
    };

    string str = "codeleet";

    int result = s.numRookCaptures(c);
    cout<<result<<endl;
}
