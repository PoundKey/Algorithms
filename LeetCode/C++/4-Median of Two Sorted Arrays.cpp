// Thoughts: Merge two vectors, and find its median, Runtime O(n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec = merge(nums1, nums2);
        if (vec.size() % 2 == 1) {
            return vec[vec.size()/2];
        } else {
            int u = vec[vec.size()/2];
            int v = vec[vec.size()/2 - 1];
            return double(u + v)/2;
        }
        
    }
    
    vector<int> merge(vector<int> l1, vector<int> l2) {
        vector<int> res;
        int m = l1.size(), n = l2.size();
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i < m && (j >= n || l1[i] <= l2[j])) {
                res.push_back(l1[i++]);
            } else {
                res.push_back(l2[j++]);
            }
        }
        return res;
    }
};

// Thoughts: //TODO Runtime: O(log(m+n))