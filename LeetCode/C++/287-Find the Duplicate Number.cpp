// Thoughts: Pigeon Hole principle.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            if (set.count(nums[i])) return nums[i];
            set.insert(nums[i]);
        }
    }
};

// Use binary search to acquire O(1) space.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int count = 0;
            for (auto& i : nums) {
                if (i <= mid) count++;
            }
            if (count <= mid)
                start = mid + 1;
            else 
                end = mid - 1;
        }
        return start;
    }
};