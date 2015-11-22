// Thoughts: Don't think to deep. A[i] is based on A[i-1]'s pronounciation.
// Have two variables keep track of the the prev character and count.
// Once the prev haracter changed when scanning, append count + prev char.
class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        string res = "1";
        for (int i = 2; i <= n; i++) {
            string temp = "";
            char prev = res[0];
            int count = 1;
            for (int j = 1; j < res.size(); j++) {
                if (res[j] == res[j-1]) {
                    count++;
                } else {
                    temp += to_string(count);
                    temp += prev;
                    prev = res[j];
                    count = 1;
                }
            }
            temp += to_string(count);
            temp += prev;
            res = temp; 
        }
        return res;
    }
};
