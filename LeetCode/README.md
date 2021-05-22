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
    
    /**
    Sliding Windows:
    1. slide in
    2. slide out
    3. update the result
    
    **/
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        if (s.empty() || k <= 0)
        {
            return 0;    
        }
        
        // uniqueCount or use map as the count
        unordered_map<char, int> dict;
        int res = 0, j = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            // slide-in 
            char c = s[i];            
            dict[c]++;
            
            // slide-out
            while (dict.size() > k)
            {
                char cad = s[j];
                dict[cad]--;
                
                if (dict[cad] == 0)
                {
                    dict.erase(cad); // remember to erase from the map
                }
                
                j++;
            }
            
            res = max(res, i - j + 1);
        }
};

```
### Left / Right Pointers (Same Direction Same Container)
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty())
        {
            return;
        }
        int anchor = 0; // refers to the position we want to swap non-zero
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[anchor]);
                anchor++;
            }
        }
    }

};

```
### Left / Right Pointers (Same Direction Two Containers)
```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        while (i >= 0 || j >= 0)
        {
            if (i >= 0 && j >= 0)
            {
                if (nums1[i] >= nums2[j])
                {
                    nums1[k] = nums1[i];
                    i--;
                }
                else
                {
                    nums1[k] = nums2[j];
                    j--;
                }
            }
            else if (i >= 0)
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
 }
```
### Left / Right Pointers (Opposite Direction)

```cpp

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty())
        {
            return;
        }
        
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    
    bool isPalindrome(string s) {
        if (s.empty()) 
        {
            return true;
        }
        int start = 0, end = s.size() - 1;
        while (start < end) 
        {
            while (start < end && !isalnum(s[start])) 
            {
                start++;
            }
            
            while (start < end && !isalnum(s[end])) 
            {
                end--;
            }
            
            if (tolower(s[start]) != tolower(s[end])) 
            {
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
    
    // Container With Most Water
    int maxArea(vector<int>& height) {
        if (height.empty())
        {
            return 0;
        }
        
        int maxArea = 0, n = height.size();
        int start = 0, end = n - 1;
        // 水桶定律：对短板作出行动
        // 有没有一首歌可以形容？
        // 向对方移动的双指针：我会耐心的等，随时欢迎你靠岸 --- 《孤单北半球》
        while (start < end)
        {
            int area = min(height[start], height[end]) * (end - start);
            maxArea = max(maxArea, area);
            if (height[start] >= height[end])
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return maxArea;
    }
}
```
### Sort + Left / Right Pointers
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


### Binary Search

