// 1. record the sum for each index i in a map, such that map[sum] = i
// 2. if for index i, map.count(sum) == true, means that between index [ map[sum] + 1, i ], the overall subarray sum is 0
// 3. return [ map[sum] + 1, i ]
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        if (nums.empty()) return vector<int>{};
        map<int, int> map;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == 0) {
                return vector<int>{0, i};
            }
            if (map.count(sum)) {
                return vector<int>{map[sum] + 1, i};
            }
            map[sum] = i;
        } 
    }
};
