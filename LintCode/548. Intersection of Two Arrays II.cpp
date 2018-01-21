class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.empty() && nums2.empty()) return res;
        if (nums1.empty() || nums2.empty()) return res;
        map<int, int> map;
        for (int i = 0; i < nums1.size(); i++) map[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++) {
            int target = nums2[i];
            if (map[target] > 0) {
                res.push_back(target);
                map[target]--;
            } 
        }
        return res;
    }
};
