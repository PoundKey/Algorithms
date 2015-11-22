// Thoughts: Two pointer with Array. i = > element ACKed
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int sum = 0, i = 0, j = 0, len = 0;
        while (j < nums.size()) {
            if (nums[j] >= s) return 1;
            sum += nums[j];
            if (len == 0 && sum >= s) len = j - i + 1;
            while (sum - nums[i] >= s) {
                sum -= nums[i];
                i++;
                len = min(len, j - i + 1);
            }
            j++;
        }
        return len;
    }
};