#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

#define ll long long

using namespace std;

class Fancy {
public:
    vector<long> v;
    vector<long> mulList;
    vector<long> addList;
    long mul = 1, add = 0, modx = 1e9+7;
    Fancy() {
        
    }
    
    void append(int val) {
        v.push_back(val);
        mulList.push_back(mul);
        addList.push_back(add);
    }
    
    void addAll(int inc) {
        add = (add + inc) % modx;
    }
    
    void multAll(int m) {
        mul = mul*m %modx;
        add = add *m % modx;
    }
    
    int getIndex(int idx) {
        int size = v.size();
        if (idx > (size - 1)) 
            return -1;
        
        long tmul = mulList[idx];
        long tadd = addList[idx];
        long val = v[idx];
        auto m = divide(mul, tmul);
        auto a = (add + modx - (tadd*m)%modx) % modx;
        return (m * val + a) % modx; 
    }

    ll power(ll a, ll b){ 
        ll x = 1, y = a % modx; 
        while (b > 0){ 
            if (b%2) x = x * y % modx; 
            y = y * y % modx; 
            b /= 2; 
        } 
        return x % modx; 
    }	 
 
    ll modular_inverse(ll n){ 
        return power(n, modx-2); 
    } 
    
    ll divide(ll a, ll b){
        return a * modular_inverse(b) % modx;
    }

    void dumpArray() {
        cout << "Mul: " << mul << " add: " << add << endl;

        for(int i=0;i<v.size();i++) {
            cout << v[i] << " " << mulList[i] << " " << addList[i] << "\t";
            
        }
        cout << endl;
    }
};

int main() {
    Fancy fancy;
    vector<string> op {"Fancy","append","append","getIndex","append","getIndex","addAll","append","getIndex","getIndex","append","append","getIndex","append","getIndex","append","getIndex","append","getIndex","multAll","addAll","getIndex","append","addAll","getIndex","multAll","getIndex","multAll","addAll","addAll","append","multAll","append","append","append","multAll","getIndex","multAll","multAll","multAll","getIndex","addAll","append","multAll","addAll","addAll","multAll","addAll","addAll","append","append","getIndex"};

    vector<vector<int>> val {{},{12},{8},{1},{12},{0},{12},{8},{2},{2},{4},{13},{4},{12},{6},{11},{1},{10},{2},{3},{1},{6},{14},{5},{6},{12},{3},{12},{15},{6},{7},{8},{13},{15},{15},{10},{9},{12},{12},{9},{9},{9},{9},{4},{8},{11},{15},{9},{1},{4},{10},{9}};

    int i = 0;
    for(string x: op) {
        if(x == "Fancy") {
            i++;
            continue;
        }

        cout << x << " " << val[i][0] << endl;
        if(x == "append") {
            fancy.append(val[i][0]);
            fancy.dumpArray();
        }
        else if(x == "multAll") {
            fancy.multAll(val[i][0]);
            fancy.dumpArray();
        }
        else if(x == "addAll") {
            fancy.addAll(val[i][0]);
            fancy.dumpArray();
        }
        else if(x == "getIndex") {
            int result = fancy.getIndex(val[i][0]);
            cout << result << endl;
        }
        i++;
    }
    /*fancy.append(2);   // fancy sequence: [2]
    fancy.dumpArray();
    fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
    fancy.dumpArray();
    fancy.append(7);   // fancy sequence: [5, 7]
    fancy.dumpArray();
    fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
    fancy.dumpArray();
    int result = fancy.getIndex(0); // return 10
    cout << result << endl;
    fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
    fancy.dumpArray();
    fancy.append(10);  // fancy sequence: [13, 17, 10]
    fancy.dumpArray();
    fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
    fancy.dumpArray();
    result = fancy.getIndex(0); // return 26
    cout << result << endl;
    result = fancy.getIndex(1); // return 34
    cout << result << endl;
    result = fancy.getIndex(2); // return 20
    cout << result << endl;*/
}