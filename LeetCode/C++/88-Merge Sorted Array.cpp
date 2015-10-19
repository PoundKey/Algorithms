// Thoughts: The easier way: do it with a helper vector temp, with size = m+n
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int size = m + n;
        vector<int> temp;
        while (i+j < size) {
          if (i < m && (j >=n || nums1[i] < nums2[j])) {
              temp.push_back(nums1[i++]);
          } else {
              temp.push_back(nums2[j++]);
          }
        }
        
        for (int k=0; k < size; k++) {
            nums1[k] = temp[k];
        }
    }
};

//Thoughts: Do it in-place, without extra memory used
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (i >=0 || j>=0) {
            if (i >= 0 && (j < 0 || nums1[i] >= nums2[j])) {
                nums1[last--] = nums1[i--];
            } else {
                nums1[last--] = nums2[j--];
            }
        }
    }
};

