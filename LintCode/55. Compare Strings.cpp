// another classical problem can be solved with hashmap
class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        if (B.empty()) return true;
        if (A.empty()) return false;
        
        map<char, int> map;
        for (int i = 0; i < A.size(); i++) {
            map[A[i]]++;
        }
        for (int j = 0; j < B.size(); j++) {
            if (!map.count(B[j])) return false;
            if (--map[B[j]] < 0) return false;
        }
        return true;
    }
};
