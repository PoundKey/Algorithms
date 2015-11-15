class Solution {
public:
    int findKthSmallest(vector<int>& nums, int k) {
        return findHelper(nums, k, 0, nums.size() - 1);
    }
    
    int findHelper(vector<int>& nums, int k , int start, int end) {
        int p = partition(nums, start, end);
        int len = p - start;
        if (k == len + 1) {
            return nums[p];
        } else if (k < len + 1) {
            return findHelper(nums, k, start, p - 1);
        } else {
            return findHelper(nums, k - len - 1, p + 1, end);
        }
    }
    int partition(vector<int>& A, int start, int end) {
        int pivot = A[end], i = start;
        for (int j = i; j < end; j++) {
            if (A[j] <= pivot) {
                swap(A[j], A[i++]);
            }
        }
        swap(A[i], A[end]);
        return i;
    }
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};