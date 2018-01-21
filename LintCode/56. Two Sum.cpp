class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (map.count(diff)) {
                return vector<int>{ map[diff] + 1, i + 1};
            } else {
                map[nums[i]] = i;
            }
        }
        return vector<int>{};
    }
};
