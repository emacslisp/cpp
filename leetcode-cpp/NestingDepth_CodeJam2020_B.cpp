#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

using namespace std;

string generate(int c) {
    string result;
    if(c==0) return "";
    if(c>0) {
        for(int i=0;i<c;i++) {
            result.push_back('(');
        }
    } else {
        for(int i=0;i<(-c);i++) {  
            result.push_back(')');
        }
    }
    return result;
}

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("NestingDepth_CodeJam2020_B.in", "r", stdin);
    freopen("NestingDepth_CodeJam2020_B.out", "w", stdout);
#endif

    int N;
    scanf("%d\n", &N);
    char s[102];
    for (int o = 0; o < N; o++)
    {
        memset(s, 0, 102*sizeof(char));
        scanf("%s\n", s);

        int i=0;
        char c = s[0];
        string t;
        string result = generate(c-'0');
        while (true) {
            if(s[i] == c) {
                t.push_back(c);
            } else {
                if(t.size() > 0) {
                    result+=(t + generate(s[i] - c));
                    t="";
                    c = s[i];
                    t.push_back(c);
                }
            }

            i++;
            if(s[i] == '\0') {
                if(t.size() > 0) {
                    result+=(t + generate('0' - t[0]));
                }
                break;
            }
        }
        
        cout << "Case #" << (o+1) << ": "<<result<<endl;
    }

#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}