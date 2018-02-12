1. use priority queue
2. practice with using quick-select
3. core principal: the kth largest number -> min_length_of(array) >= k

class Solution {
public:
    vector<int> topk(vector<int> nums, int k) {
        vector<int> res;
        if (nums.empty() || k == 0) return res;
        priority_queue<int> pq;
        
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        
        while (k > 0)
        {
            int val = pq.top();
            res.push_back(val);
            pq.pop();
            --k;
        }
        return res;
    }
     
    vector<int> topkQuickSelect(vector<int> nums, int k) {
        vector<int> res;
        if (nums.empty() || k == 0) return res;
        int n = nums.size();
        for (int i = 0; i < k; ++i)
        {
            int val = QuickSelect(nums, n - i, 0, n - 1);
            res.push_back(val);
        }
        return res;
    }
    
    int QuickSelect(vector<int>& A, int k, int start, int end)
    {
        if (A.empty() || k < 1 || start > end) return -1;
        int pos = Partition(A, start, end);
        int count = pos - start + 1;
        if (count == k)
        {
            return A[pos];
        }
        else if (count > k)
        {
            return QuickSelect(A, k, start, pos - 1);
        }
        else 
        {
            return QuickSelect(A, k - count, pos + 1, end);
        }
    }
    
    int Partition(vector<int>& A, int start, int end)
    {
        // return index
        int val = A[end];
        int i = start, j = end - 1;
        while (i <= j)
        {
            if (A[i] >= val)
            {
                Swap(A[i], A[j--]);
            }
            else
            {
                i++;
            }
        }
        Swap(A[end], A[i]);
        return i;
    }
    
    void Swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};
