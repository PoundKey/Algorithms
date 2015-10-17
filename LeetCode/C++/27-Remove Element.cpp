//solution v1: i = numbers being scanned, j = numbers being acknowledged
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0, j=0;
        for (i=0; i < nums.size(); i++) {
            if(nums[i] == val) {
                continue;
            }
            nums[j] = nums[i];
            j++;
        }
        return j;
    }
	};

//solution v2: move the element to the end of the vector and pop out
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it = find(nums.begin(), nums.end(), val);
        while (it != nums.end()) {
            int last = nums.size() - 1;
            int index = it - nums.begin();
            nums[index] = nums[last];
            nums.pop_back();
            it = find(nums.begin(), nums.end(), val);
        }
        return nums.size();
    }
	};