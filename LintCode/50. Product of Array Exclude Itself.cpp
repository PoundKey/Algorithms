// trade space for time
class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        vector<long long> res;
        if (nums.empty()) return res;
        long long val = 1, n = nums.size();
        vector<long long> forwardProduct(n, 1);
        vector<long long> backwardProduct(n, 1);
        
        for (int i = 1; i < n; i++) {
            forwardProduct[i] = forwardProduct[i-1] * nums[i-1];
        }
   
        for (int i = n - 2; i >= 0 ; i--) {
            backwardProduct[i] = backwardProduct[i+1] * nums[i+1];
        } 
        for (int i = 0; i < n; i++) {
            res.push_back(forwardProduct[i] * backwardProduct[i]);
        }
        return res;
    }
    
    vector<long long> productExcludeItselfBruteforce(vector<int> &nums) {
        vector<long long> res;
        if (nums.empty()) return res;
        for (int i = 0; i < nums.size();i++) {
            long long val = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                val *= nums[j];
            }
            res.push_back(val);
        }
        return res;
    }    
};
