## LeetCode Daily Practices

## Two Pointers
### Sliding Windows
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
        {
            return 0;
        }
        
        unordered_map<char, int> dict;
        int res = 1, j = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            dict[c]++; // slide in
            while (dict[c] > 1)
            {
                dict[s[j]]--;
                j++;
            }
            
            res = max(res, i - j + 1);
        }
        
        return res;
    }
};

```

### Sort + Left / Right
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
        {
            return res;
        }
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
            {
                continue;  
            }
            
            int target = -nums[i];
            int start = i + 1, end = n - 1;
            
            while (start < end)
            {
                int value = nums[start] + nums[end];
                if (value == target)
                {
                    res.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    
                    // duplicate
                    while (start < n && nums[start] == nums[start-1])
                    {
                        start++;
                    }
                    while (end > i && nums[end] == nums[end+1])
                    {
                        end--;
                    }
                }
                else if (value > target)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
        
        return res;
    }
};
```
