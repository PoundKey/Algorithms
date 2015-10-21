// Thoughts: Brute force, for 0..i, compute the area that btween region h[i] <= h[left] and i <= h[right]
// Runtime: O(n^2)
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int maxArea = 0 ;
        for (int i=0; i < height.size(); i++) {
            maxArea = max(maxArea, calcArea(height, i));
        }
        return maxArea;
    }
    
    int calcArea(vector<int>& height, int index) {
        int left = index - 1;
        int right = index + 1;
        while (left >=0 && height[index] <= height[left]) {
            left--;
        }
        while (right < height.size() && height[index] <= height[right]) {
            right++;
        }
        return (right - left - 1) * height[index];
    }
};

// Throughts: for each i, look for left and right, the the left most index with h[left] < h[i];
// and right most index with h[right] < h[i], compute and area using a stack that contains all necessary indices.
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
       int maxArea = 0;
       height.push_back(-1);
       height.insert(height.begin(), -1);
       stack<int> s;
       s.push(0);
       int i = 1;
       while ( i < height.size()) {
           if (height[s.top()] <= height[i]) {
               s.push(i);
               i++;
           } else {
              int h = height[s.top()];
              s.pop();
              int area = (i - s.top() - 1) * h;
              maxArea = max(maxArea, area);             
           }
       }
       return maxArea;
    }
};