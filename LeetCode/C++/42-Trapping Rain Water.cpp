// Thoughts: Water is trapped in i if and only if there existes A[left], left < i,
// and A[right], right > i, such that min(A[left], A[right]) > A[i]
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        if (n < 3) return total;
        vector<int> leftHigh(n);
        leftHigh[0] = 0;
        for (int i = 1; i < n; i++) {
            leftHigh[i] = max(height[i-1], leftHigh[i-1]);
        }
        
        int rightHigh = 0, minVal;
        
        for (int i = n - 2; i > 0; i--) {
            rightHigh = max(rightHigh, height[i+1]);
            minVal = min(leftHigh[i], rightHigh);
            total += minVal > height[i] ? minVal - height[i] : 0;
        }
        return total;
    }
};