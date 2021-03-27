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

char calc(char a, char b, map<string, int> m) {
    vector<char> v;
    v.push_back('C');
    v.push_back('J');
    int min = INT_MAX;
    char target;
    for(char x: v) {
        int total = 0;
        string t1 = "";
        string t2 = "";
        t1.push_back(a);
        t1.push_back(x);

        t2.push_back(x);
        t2.push_back(b);
        if(m.count(t1)) {
            total += m[t1];
        }

        if(m.count(t2)) {
            total += m[t2];
        }

        if(min > total) {
            min = total;
            target = x;
        }
    }
    
    return target;
}

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("MoonsAndUmbrellas_B_QR_2021.in", "r", stdin);
    freopen("MoonsAndUmbrellas_B_QR_2021.out", "w", stdout);
#endif

    int T;
    scanf("%d\n", &T);
    char array[1000];
    for (int o = 1; o <= T; o++)
    {
        int X, Y;
        scanf("%d %d ", &X, &Y);
        memset(array, '0', 1000*sizeof(char));

        char tc='0';
        int counter = 0;

        map<string, int> m;
        m["CJ"] = X;
        m["JC"] = Y;
        while(scanf("%c", &tc) != EOF) {
            if(tc == '\n') break;
            array[counter++] = tc;
        }
        vector<char> v;
        v.push_back('0');
        for(int i=0;i<counter;i++) {
            int c2 = 0;
            if(array[i] == '?') {
                c2++;
            } else{
                if(c2%2 == 1) {
                    v.push_back('?');
                }
                v.push_back(array[i]);
            }
        }
        v.push_back('0');
        int result = 0;
        for(int i=1;i<v.size() - 1;i++) {
            if(v[i] == '?') {
                v[i] = calc(v[i-1], v[i+1], m);
            } 
        }

        for(int i=1;i<v.size() - 2;i++) {
            string t = "";
            t.push_back(v[i]);
            t.push_back(v[i+1]);
            if(m.count(t)) {
                result += m[t];
            }
        }
        cout << "Case #" << o <<": "<< result << endl;
    }

#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}