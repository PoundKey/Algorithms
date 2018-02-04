// 1. three cases:
//  1.1 missing number is at the beginning of the array
//  1.2 missing number is at the middle of the array
//  1.3 missing number is at the end of the array

class Solution {
public:
    int findMissing(vector<int> nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for (int i = 0; i < n; i++)
        {
            sum -= nums[i];
        }
        return sum;
    }
    
    int findMissing(vector<int> nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = res ^ (i ^ nums[i]);
        }
        res ^= n;
        return res;
    }
    
    int findMissing(vector<int> nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        set<int> s;
        for (int i = 0; i <= n; i++)
        {
            s.insert(i);
        }
        for (int i = 0; i < n; i++)
        {
            if (s.count(nums[i]) == 0)
            {
                return nums[i];
            }
            else
            {
                s.erase(nums[i]);
            }
        }
        return *s.begin(); // single missing item left in the set
    }
    
    int findMissingBruteforce(vector<int> nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[0] != 0) return 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] + 1 != nums[i + 1])
            {
                return nums[i] + 1;
            }
        }
        return nums[n - 1] + 1; // the missing number is last number plus 1
    }    
};
