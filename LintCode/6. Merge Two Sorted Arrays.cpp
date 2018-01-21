class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) 
    {
        vector<int> res;
        int m = A.size(), n = B.size();
        int i = 0, j = 0;
        while (i < m || j < n) 
        {
            if (i < m && (j >= n || A[i] <= B[j])) 
            {
                res.push_back(A[i++]);
            } 
            else 
            {
                res.push_back(B[j++]);
            }
        }
        return res;
    }
};
