// Thoughts: Wikipedia Grey Code
class Solution {
public:
    vector<int> grayCode(int n) {   
        vector<int> ret;   
        int size = 1 << n;   
        for(int i = 0; i < size; ++i)   
            ret.push_back((i >> 1)^i);   
        return ret;   
    }   
};