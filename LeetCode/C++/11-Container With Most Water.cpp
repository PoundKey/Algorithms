// Thoughts: Notice that i to j are sorted, two pointer strategy can be applied under such circumstance.
// the width, j - i could not get any larger, we could only hope that the height gets larger.
// moving two pointers to the middle to find if such height exists.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int left = 0, right = height.size()-1;
        while (left < right) {
            int currArea = (right - left) * min(height[left], height[right]);
            area = max(area, currArea);
            if (height[left] < height[right]) {
                left++;
            } else if (height[left] > height[right]) {
                right--;
            } else {
                left++;
                right--;
            }
        }
        return area;
    }
};
