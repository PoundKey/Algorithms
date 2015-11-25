// Thoughts: Key to the problem: for newly added element with index i, if A[i] > A[x],
// where x < i, meaning that A[i] is the best candidate for the maxVal with the window.
// we use a deque to keep the best candidate on its front, and also all possible candidates.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        if (nums.empty() || k == 0) return res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!q.empty() && q.front() == i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            if (i - k + 1 >= 0) res.push_back(nums[q.front()]);
        }
        return res;
    }
};

// Thouguts: Brute Force O(nk)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty() || k == 0) return res;
        int n = nums.size(), i = 0, j = k - 1;
        while (j < n) {
            int curMax = findMax(nums, i, j);
            res.push_back(curMax);
            i++; j++;
        }
        return res;
    }
    int findMax(vector<int>& nums, int start, int end) {
        int maxVal = nums[start];
        for (int i = start + 1; i <= end; i++) {
            maxVal = max(maxVal, nums[i]);
        }
        return maxVal;
    }
};