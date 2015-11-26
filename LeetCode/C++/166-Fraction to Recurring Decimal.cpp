// Thoughts: 
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        int sign = (numerator > 0 && denominator > 0 || numerator < 0 && denominator < 0) ? 1 : -1;
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        long long quo = n / d;
        long long rem = n % d;
        unordered_map<long long, int> map; // key: reminder => value: pos
        string res = to_string(quo);
        if (sign < 0) res = "-" + res;
        if (rem == 0) return res;
        res += ".";
        string str;
        int pos = 0;
        while (rem != 0) {
            if (map.count(rem)) {
                str.insert(map[rem], "(");
                str += ")";
                return res + str;
            }
            map[rem] = pos;
            str += to_string((rem * 10) / d);
            rem = (rem * 10) % d;
            pos++;
        }
        return res + str;
    }
};