// Thoughts: Sort the vector first O(nlogn), and reduce it to a 2sum problem
// Remove dulpicate: consider: [2, 2, 3, 4], target = 9. Here we have dulpicates.
// Key is to skip i if A[i-1] == A[i], same for return val from 2sum
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector< vector<int> > sol;
        if (num.size() < 3) return sol;
        sort(num.begin(), num.end());
        
        for (int i=0; i < num.size()-2; i++) {
            if (i>0 && num[i] == num[i-1]) continue;
            int target = 0 - num[i];
            int start = i + 1;
            int end = num.size() - 1;
            while (start < end) {
                 int sum = num[start] + num[end];
                 if (sum == target) {
                    vector<int> entry;
                    entry.push_back(num[i]);
                    entry.push_back(num[start++]);
                    entry.push_back(num[end--]);
                    sol.push_back(entry);
                    while(num[start] == num[start-1]) start++;
                    while(num[end] == num[end+1]) end--;
                } else if (sum < target) {
                    start++;
                } else {
                    end--;
                }              
            }
        }
    }
};
