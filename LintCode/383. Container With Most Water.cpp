class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        if (heights.empty()) return 0;
        int n = heights.size(), maxArea = 0;
        int start = 0, end = n - 1;
        while (start < end) {
            int curArea = min(heights[start], heights[end]) * (end - start);
            maxArea = max(maxArea, curArea);
            if (heights[start] <= heights[end]) {
                start++;
            } else {
                end--;
            }
        }
        return maxArea;
    }
    
    int maxAreaN2(vector<int> &heights) {
        if (heights.empty()) return 0;
        int n = heights.size(), maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int area = min(heights[i], heights[j]) * (j - i);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
