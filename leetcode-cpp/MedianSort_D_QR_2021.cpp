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

void query(int a, int b, int c) {
    cout << a << " " << b << " " << c << endl;
}

int main(int argc, char **argv)
{
#ifdef FILEIO
    freopen("MedianSort_D_QR_2021.in", "r", stdin);
    freopen("MedianSort_D_QR_2021.out", "w", stdout);
#endif
    int N, T, Q;
    scanf("%d", &T);
    scanf("%d", &N);
    scanf("%d", &Q);

    for (int o = 1; o <= T; o++)
    {
        int counter = 3;
        query(1, 2, 3);

        int x;
        scanf("%d", &x);

        vector<int> v;
        for(int i=1;i<=3;i++) {
            if(i!=x) {
                v.push_back(i);
            }
        }
        v.push_back(x);
        int t = v[1];
        v[1] = x;
        v[2] = t;

        while(counter < N) {
            counter++;

            int start = 0;
            int end = v.size() - 1;
            while(start < end) {
                int mid = (start + end)/2;
                if(mid == start) mid = end;
                query(v[start],v[mid], counter);
                scanf("%d", &x);

                if(x==v[mid]) {
                    if(mid == end) {
                        v.insert(v.begin() + end + 1, counter);
                        break;
                    }
                    start = mid;
                    continue;
                } else if (counter == x) {
                    end = mid;

                    if(end - start == 1) {
                        v.insert(v.begin()+end, counter);
                        break;
                    }

                    continue;
                } else if(v[start] == x) {
                    v.insert(v.begin()+start, counter);
                    break;
                }
            }
        }

        string result = "";
        for(int i=0;i<v.size()-1;i++)
        {
            result += (to_string(v[i]) + " ");
        }

        result += to_string(v[v.size() - 1]);

        cout << result << endl;
        // scan output
        scanf("%d", &x);
    }
#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}