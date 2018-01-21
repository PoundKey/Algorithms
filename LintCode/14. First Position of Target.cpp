// 1. binary search, and set condition A[mid] >= high, move high pointer the left: high = mid - 1
// 2. eventually low will pass high, make sure low is in-bound and equal to the target
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int start = 0;
        int end = array.size() - 1;
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (array[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if (start < array.size() && array[start] == target) {
            return start;
        } else {
            return -1;
        }
    }
};
