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

class MyHashSet {
public:
    map<int,int> m;
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(m.count(key) == 0) {
            m[key] = 1;
        }
    }
    
    void remove(int key) {
        if(m.count(key) == 1)
            m.erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return m.count(key) == 1;
    }
};

int main() {
    MyHashSet myHashSet;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "codeleet";

    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    bool result;
    result = myHashSet.contains(1); // return True
    cout<< result << endl;
    result = myHashSet.contains(3); // return False, (not found)
    cout<< result << endl;
    myHashSet.add(2);      // set = [1, 2]
    result = myHashSet.contains(2); // return True
    cout<< result << endl;
    myHashSet.remove(2);   // set = [1]
    result = myHashSet.contains(2); // return False, (already removed)
    cout<< result << endl;
}