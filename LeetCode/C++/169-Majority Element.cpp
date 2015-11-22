// Thoughts: Runtime O(n), Space O(n): 
// https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
// Use hashmap to achieve runtime O(n) and space O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (candidate == nums[i]) {
                count++;
            } else if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else {
                count--;
            }
        }
        count = 0;
        for (int i : nums) if (i == candidate) count++;
        return count < (nums.size() + 1) / 2 ? -1 : candidate;
    }
};