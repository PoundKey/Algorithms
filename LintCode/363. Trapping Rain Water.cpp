class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        if (heights.size() < 3) return 0;
        int n = heights.size();
        vector<int> leftMax(n, 0);
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], heights[i-1]);
        }
        
        vector<int> rightMax(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], heights[i+1]);
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
           int minHeight = min(leftMax[i], rightMax[i]);
           if (minHeight > heights[i]) {
               res += (minHeight - heights[i]);
           }
        }
        return res;
    }
};
