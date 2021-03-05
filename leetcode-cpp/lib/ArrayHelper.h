#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

class ArrayHelper {
public:
    vector<int> revert(vector<int> c);
    int maxSubArray(vector<int> c);
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
    void bubbleSort(vector<int> &nums);
    void swap(int *a, int *b);
    int search(vector<int> &num, int target);
    int subArrayEqualsK(vector<int> num, int k);
    int minimumPathSum(vector< vector<int> >& grid);
    void MainEntry();
};