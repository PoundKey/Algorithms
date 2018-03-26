class Solution {
public:
    /**
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
     
    int findDuplicate(vector<int> &nums) {
        if (nums.empty()) return -1;
        int n = nums.size();
        int start = 1, end = n - 1;
        
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int counter = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] <= mid)
                {
                    counter++;
                }
            }
            if (counter > mid)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
    
    int findDuplicateAlt(vector<int> &nums) {
        if (nums.empty()) return -1;
        set<int> set;
        for (const auto& it : nums)
        {
            if (set.count(it)) return it;
            set.insert(it);
        }
        return -1;
    }
};
