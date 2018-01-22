class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    static bool compare1(int a, int b) {
        string temp1 = to_string(a);
        string temp2 = to_string(b);
        // str1 = longer string, str2 = shorter string
        string str1, str2;
        if (temp1.size() >= temp2.size()) {
            str1 = temp1;
            str2 = temp2;
        } else {
            str1 = temp2;
            str2 = temp1;
        }
        int i = 0, j = 0;
        int m = str1.size(), n = str2.size();
        string larger;
        while (i < m) {
            if (str1[i] > str2[j]) {
                larger = str1;
                break;
            } else if (str1[i] < str2[j]) {
                larger = str2;
                break;
            } else {
                i++;
                j++;
            }
            if (j == n && i != m) j = 0;
        }
        return temp1 == larger ? true : false;
    }
    static bool compare2(int a, int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    string largestNumber(vector<int> &num) {
        if (num.empty()) return "";
        sort(num.begin(), num.end(), compare2);
        if (num[0] == 0) return "0";
        string res;
        for (int i = 0; i < num.size(); i++) {
            res += to_string(num[i]);
        }
        return res;
    }
};
