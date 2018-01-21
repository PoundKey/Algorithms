class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
     
    void sortIntegers(vector<int>& A) {
        if (A.empty()) return;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (A[j] < A[min])
                    min = j;
            }
            swap(A[i], A[min]);
        }
    }

    void InsertionSort(vector<int>& A) {
        if (A.empty()) return;
        int n = A.size();
        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0; j--) {
                if (A[j] < A[j-1])
                    swap(A[j], A[j-1]);
                else 
                    continue;
            }
        }
    }
    
    void BubbleSort(vector<int>& A) {
        if (A.empty()) return;
        int n = A.size();
        for (int i = n-1; i > 0; i--) {
            for (int j = 0; j < i; j++)
            {
                if (A[j] > A[j+1]) {
                    swap(A[j], A[j+1]);
                }
            }
        }
        
    }    
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
