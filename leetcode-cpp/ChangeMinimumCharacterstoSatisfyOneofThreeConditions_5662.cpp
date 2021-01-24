#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

using namespace std;


class Solution {
public:
    int count(string a, string b) {
		int result = INT_MAX;
		int t = 0;
		for(int i=1;i<26;i++) {
			t = 0;
			for(int j=0;j<a.length();j++) {
				if((a[j] - 'a') >=i) t++;
			}
			
			for(int j=0;j<b.length();j++) {
				if((b[j] - 'a') <i) t++;
			}
			result = min(result, t);
		}
		
		return result;
	}
    int minCharacters(string a, string b) {
        vector<int> v(26, 0);
        
        for(int i=0;i<a.size();i++) {
            v[a[i] - 'a'] += 1;
        }
        
        for(int i=0;i<b.size();i++) {
            v[b[i] - 'a'] += 1;
        }
        
        int condition1 = count(a, b);
        int condition2 = count(b, a);

        // condition 3;
        int max = 0;

        for(int i=0;i<26;i++) {
            if(max < v[i]) {
                max = v[i];
            }
        }

        max = a.length() + b.length() - max;

        return min(max, min(condition1, condition2));
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string a = "bd";
    string b = "beae";

    int result = s.minCharacters(a, b);
    cout<<result<<endl;
}