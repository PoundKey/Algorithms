// Thoughts: Recursion for the win! (Tail to tip)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > vec;
        if (numRows == 0) return vec;
        trace(vec, numRows-1);
        return vec;
    }
    
    void trace(vector< vector<int> >& vec, int index) {
        vector<int> v(index+1, 0);
        if (index == 0) {
            v[0] = 1;
            vec.push_back(v);
            return;
        }
        trace(vec, index-1);
        v[0] = 1;
        v[index] = 1;
        for(int i=1; i<index; i++) {
            v[i] = vec[index-1][i-1] + vec[index-1][i];
        }
        vec.push_back(v);
    }
};

// Thoughts: Tip to tail approach
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > res;
        if (numRows == 0) return res;
        for (int i=0; i < numRows; i++) {
            if (i==0) {
                vector<int> vec(1, 1);
                res.push_back(vec);
            } else {
                vector<int> vec(i+1, 0);
                vec[0] = 1;
                vec[i] = 1;
                for (int j=1; j < i; j++) {
                    vec[j] = res[i-1][j] + res[i-1][j-1];
                }
                res.push_back(vec);
            }
        }
        return res;
    }
};

// Easier version
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vals;
        vals.resize(numRows);
        
        for(int i = 0; i < numRows; i++) {
            vals[i].resize(i + 1);
            vals[i][0] = 1;
            vals[i][vals[i].size() - 1] = 1;
            for(int j = 1; j < vals[i].size() - 1; j++) {
                vals[i][j] = vals[i - 1][j - 1] + vals[i - 1][j];
            }
        }
        return vals;
    }
};
