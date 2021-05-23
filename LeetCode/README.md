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
    
    // Intersection of three sorted arrays
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        
        vector<int> res;
        int p1 = 0, p2 = 0, p3 = 0;
        
        while (p1 < arr1.size() && p2 < arr2.size() && p3 < arr3.size()) 
        {
            if (arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3]) 
            {
                res.push_back(arr1[p1]);
                p1++;
                p2++;
                p3++;
            } 
            else 
            {
                // move pointer with the smaller value forward
                if (arr1[p1] < arr2[p2]) 
                {
                    p1++;
                } 
                else if (arr2[p2] < arr3[p3]) 
                {
                    p2++;
                } 
                else // arr1[p1] > arr2[p2] > arr3[p3] 
                {
                    p3++;
                }
                
                /**
                identify the the temp max, move the counter
                int tmp = max(arr1[p1], max(arr2[p2], arr3[p3]));
                while (p1 < n1 && arr1[p1] < tmp) p1++;
                while (p2 < n2 && arr2[p2] < tmp) p2++;
                while (p3 < n3 && arr3[p3] < tmp) p3++;
                **/
            }
        }
        return res;       
    }
 }
```

### Slow / Fast Pointer (Same Direction)
```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) 
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }
        }
        
        return false;
    }
};

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
    /**
    977. Squares of a Sorted Array
    Input: nums = [-7,-3,2,3,11]
    Output: [4,9,9,49,121]
    **/
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> res(n);
        
        int left = 0, right = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            /**
            1. populate the res from end of start
            2. the candidates are:
                2.1 left most number
                2.2 right most number
            3. compare their absolute val, and increment left pointer or decrement right pointer if it's selected
            **/
            int candidate;
            if (abs(nums[left]) > abs(nums[right]))
            {
                candidate = nums[left];
                left++;
            }
            else
            {
                candidate = nums[right];
                right--;
            }
            
            res[i] = candidate * candidate;
        }
        
        return res;
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
#### Regular Binary Search: 

First Occurrence + Last Occurence
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = searchFirst(nums, target);
        int end = searchLast(nums, target);
        return vector<int>{start, end};
    }
    
    int searchFirst(vector<int>& nums, int target)
    {
        int n = nums.size();
        int start = 0, end = n - 1;
        int res = -1;
        
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                res = mid;
                end = mid - 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else 
            {
                start = mid + 1;
            }
        }

        return res;
    }
    
    int searchLast(vector<int>& nums, int target)
    {
        int n = nums.size();
        int start = 0, end = n - 1;
        int res = -1;
        
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                res = mid;
                start = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else 
            {
                start = mid + 1;
            }
        }

        return res;    
    }
    
    // Sqrt of x: use left <= right, and return end
    int mySqrt(int x) {
        if (x <= 1) 
        {
            return x;
        }
        
        int start = 0, end = x;  
        while (start <= end) 
        {
            int mid = start + (end - start) / 2;
            if (x / mid == mid) 
            {
                return mid;
            } 
            else if (x / mid < mid) 
            {
                end = mid - 1;
            } 
            else 
            {
                start = mid + 1;
            }
        }
        
        return end;
    }
};



```
#### Prefix Sum + Binary Search
```cpp
class Solution {
private:
    vector<int> d_prefixSum;
public:
    Solution(vector<int>& w) {
        for (int i = 0; i < w.size(); i++)
        {
            // 打平成一个一维有序排列
            // 1. 蛋糕的总数有多大 -> 线段总长度 sum
            // 2. 群雄割据 -> everybody occupies part of the sum
            int value = w[i];
            if (d_prefixSum.empty())
            {
                d_prefixSum.push_back(value);
            }
            else
            {
                d_prefixSum.push_back(d_prefixSum.back() + value);
            }
        }
            
    }
    
    int pickIndex() {
        if (d_prefixSum.empty())
        {
            return -1;
        }
        
        int randnum = rand() % d_prefixSum.back() + 1;

        auto it = std::lower_bound(d_prefixSum.begin(), d_prefixSum.end(), randnum);
        
        return it - d_prefixSum.begin();
    }
};

```

#### Search Space
```cpp
class Solution {
public:
    // 搜索区间定乾坤
    // 33. Search in Rotated Sorted Array
    int search(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return -1;
        }
        
        int start = 0, end = nums.size() - 1;
        
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] >= nums[start]) // rotated second half
            {
                if (nums[mid] > target && nums[start] <= target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else // rotated first half
            {
                if (nums[mid] < target && nums[end] >= target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
}
```

#### Matrix + Binary Search
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int row = 0, col = matrix[0].size() - 1;
        
        while (row < matrix.size() && col >= 0) 
        {
            if (target > matrix[row][col])
            {
                row++;
            }
            else if (target < matrix[row][col])
            {   
                col--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};


```

#### Recursion + Binary Search
```cpp
class Solution {
public:
    double fastPow(double x, long long n) 
    {
        if (n == 0) 
        {
            return 1.0;
        }
        
        double half = fastPow(x, n / 2);
        
        if (n % 2 == 0) 
        {
            return half * half;
        } 
        else 
        {
            return half * half * x;
        }
    }
    
    double myPow(double x, int n) 
    {
        // 1. case: n is negative => invert x to 1/x and turn n to positive
        // 2. case: n is positve
        long long N = n;
        // convert N to non-negative value
        if (N < 0) 
        {
            x = 1 / x;
            N = -N;
        }
        
        return fastPow(x, N);
    }
};

```
