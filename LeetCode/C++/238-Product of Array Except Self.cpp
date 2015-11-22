// Thoughts: Scan from the left and save the leftProduct, and do a second scan from the right
// save the rightProduct so far. result[i] = leftProduct[i] * rightProduct[i]
// Time Complexity: O(n), Space Complexity: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1), leftProduct(n, 1), rightProduct(n, 1);
        for (int i = 1; i < n; i++) {
            leftProduct[i] = leftProduct[i-1] * nums[i-1];
        }
        for (int i = n - 2; i >= 0; i--) {
            rightProduct[i] = rightProduct[i+1] * nums[i+1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = leftProduct[i] * rightProduct[i];
        }
        return res;
    }
};

// Thoughts: Let's optimize this a bit with space complexity O(1).
// Same idea but use the response vector as the intermediate container.
// Sort like dynamic programing... huh?
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++) {
            res[i] = res[i-1] * nums[i-1];
        }
        int rightProduct = 1;
        for (int i = n - 2; i >= 0; i--) {
            rightProduct *= nums[i+1];
            // result[i] = leftProduct[i] * rightProduct[i]
            res[i] = res[i] * rightProduct; 
        }
        return res;
    }
};

// Thoughts: Brute Force, Time limit exceeded.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int val = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (j == i) continue;
                val *= nums[j];
            }
            res.push_back(val);
        }
        return res;
    }
};
