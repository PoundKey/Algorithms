class Solution {
public:
    /*
     * @param A: an integer ratated sorted array and duplicates are allowed
     * @param target: An integer
     * @return: a boolean 
     */
    bool search(vector<int> &A, int target) {
        if (A.empty()) return false;
        int n = A.size(), start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) return true;
            else if (A[mid] > A[start]) // sorted left half
            {
                if (target < A[mid] && target >= A[start])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else if (A[mid] < A[start]) // sorted right half
            {
                if (target > A[mid] && target <= A[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else if (A[mid] == A[start]) // increase start
            {
                ++start;
            }
        }
        return false;
    }
};
