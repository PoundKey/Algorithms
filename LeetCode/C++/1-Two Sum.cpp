// Thoughts: Key: use a hashmap to store {nums[index] : index} pair, takes O(1)
// to look up if (target - nums[index]) exists in the hashmap or not. 
// Don't overlook the siutation where (diff == val && exist < 2) 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, vector<int> > imap;
        for (int i=0; i < nums.size(); i++) {
            imap[nums[i]].push_back(i); 
        }
        for (int k=0; k < nums.size(); k++) {
            int val = nums[k];
            int diff = target - val;
            int exist = imap[diff].size();
            
            if (exist) {
                if (diff == val && exist < 2) continue;
                int index = (exist == 1) ? 0 : 1;
                res.push_back(imap[val][0] + 1);
                res.push_back(imap[diff][index] + 1);
                return res;                
            }
        }
    }
};