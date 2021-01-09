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


class ProductOfNumbers {
public:
    vector<int> nums;
    vector<int> mul;

    ProductOfNumbers() {
        mul.push_back(1);
    }
    
    void add(int num) {
        if(num == 0) {
            mul.clear();
            mul.push_back(1);
            nums.push_back(num);
        } else {
            nums.push_back(num);
            mul.push_back(num * mul[mul.size() - 1]);    
        }
    }
    
    int getProduct(int k) {
        int i = mul.size() - k - 1;
        if(i < 0) {
            return 0;
        }
        return mul[mul.size() - 1]/mul[i];
    }
};

int main() {
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);        // [3]
    productOfNumbers.add(0);        // [3,0]
    productOfNumbers.add(2);        // [3,0,2]
    productOfNumbers.add(5);        // [3,0,2,5]
    productOfNumbers.add(4);        // [3,0,2,5,4]
    int result = productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
    cout<<result<<endl;
    result = productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    cout<<result<<endl;
    result = productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 
    cout<<result<<endl;

    productOfNumbers.add(8);
    result = productOfNumbers.getProduct(2); 
    cout<<result<<endl;
}