// Thoughts: res[j] = res[j] + res[j-1];
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        res[0] = 1;
        for (int i=1; i<= rowIndex; i++) {
            for (int j=i; j>0; j--) {
                res[j] = res[j] + res[j-1];
            }
        }
        return res;
    }
};


// Thoughts: Generate the entire Pascal's Triangle with n+1 rows, and return T[n];
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        return generate(rowIndex + 1)[rowIndex];
    }
    
    vector< vector<int> > generate(int n) {
        vector< vector<int> > res;
        res.resize(n);
        for (int i=0; i < n; i++) {
            res[i].resize(i+1);
            int size = res[i].size();
            res[i][0] = 1;
            res[i][size-1] = 1;
            for (int j=1; j < size-1; j++) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;   
    }
};