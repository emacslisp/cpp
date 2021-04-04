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
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
        if(sr < 0 || sc <0) return;
        if(sr >= image.size() || sc >= image[0].size()) return;
        if(image[sr][sc] == newColor) return;
        
        if(image[sr][sc] != oldColor) return;

        image[sr][sc] = newColor;

        dfs(image, sr+1, sc,newColor, oldColor);
        dfs(image, sr-1, sc,newColor, oldColor);
        dfs(image, sr, sc+1,newColor, oldColor);
        dfs(image, sr, sc-1,newColor, oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{1,1,1},{1,1,0},{1,0,1}};

    string str = "codeleet";
    int n = 1804289383;
    int sr = 1;
    int sc = 1;
    int newColor = 2;
    vector<vector<int>> result = s.floodFill(c,sr,sc,newColor);
    for(vector<int> x: result) {
        for(int y: x) {
            cout<<y<<' ';
        }
        cout << endl;
    }
    
}