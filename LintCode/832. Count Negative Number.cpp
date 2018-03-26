// 1. of course, we could bruteforce the entire matrix, runtime O(n * m)
// 2. foreach row, we find the index of the first non-negative number using binary search, runtime O(n * log(m))
// 3. start from the top right corner of first row, find the index of the first negative number, mark this as j;
//    the key is that for the following row, j could only be smaller due to the sorted property of the matrix.
//    the runtime is O(n + m)

class Solution {
public:
    /**
     * @param nums: the sorted matrix
     * @return: the number of Negative Number
     */
    int countNumber(vector<vector<int>> &nums) {
        if (nums.empty() || nums[0].empty()) return 0;
        int n = nums.size(), m = nums[0].size();
        int counter = 0;
        int j = m - 1;
        for (int i = 0; i < n; i++)
        {
            if (j < 0) break;
            while (j >= 0)
            {
                if (nums[i][j] < 0) break;
                --j;
            }
            counter += j + 1;
        }
        return counter;
    }
    
    int countNumberAlt(vector<vector<int>> &nums) {
        if (nums.empty() || nums[0].empty()) return 0;
        int n = nums.size(), m = nums[0].size();
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i][0] >= 0) break;
            counter += BinarySearch(nums[i]);
        }
        return counter;
    }
    
    // find the index of the first non-negative number
    int BinarySearch(const vector<int>& A)
    {
        if (A.empty()) return -1;
        if (A[0] >= 0) return 0;
        
        int n = A.size();
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (A[mid] >= 0)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
};
