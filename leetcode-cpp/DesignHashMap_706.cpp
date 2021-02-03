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


class MyHashMap {
public:
    map<int,int> m;
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        m[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if(m.count(key) == 0) return -1;

        return m[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if(m.count(key) == 0) return;
        m.erase(key);
    }
};

int main() {
    MyHashMap hashMap;
    hashMap.put(1, 1);          
    hashMap.put(2, 2);  
    int result;       
    result = hashMap.get(1);            // returns 1
    cout << result << endl;
    result = hashMap.get(3);            // returns -1 (not found)
    cout << result << endl;
    hashMap.put(2, 1);          // update the existing value
    result = hashMap.get(2);            // returns 1 
    cout << result << endl;
    hashMap.remove(2);          // remove the mapping for 2
    result = hashMap.get(2);            // returns -1 (not found) 
    cout << result << endl;
}