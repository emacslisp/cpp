#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

#define Max(a, b) a > b ? a : b
short int c[5001][5001];

int LCS(string s1, string s2) {
    memset(c, 0, sizeof(c));

    for(int i=1;i<=s1.size();i++) {
        for(int j=1;j<=s2.size();j++) {
            if(s1[i-1] == s2[j-1]) {
                c[i][j] = 1 + c[i-1][j-1];
            } else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }

    return c[s1.size()][s2.size()];
}

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("Palindrome_poj1159.in", "r", stdin);
    freopen("Palindrome_poj1159.out", "w", stdout);
#endif

    int N;
    scanf("%d\n", &N);

    string s;
    char c[N];
    for(int i=0;i<N;i++) {
        scanf("%c", &c[i]);
        s.push_back(c[i]);
    }

    string r;
    for(int i=s.size() - 1;i>=0;i--) {
        r.push_back(s[i]);
    }

    printf("%d\n", N - LCS(s, r));
    
#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}