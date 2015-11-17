// Thoughts: for num a and b, if str(a) + str(b) > str(b) + str(a), then a should be placed in front of b
// and vice versa. Overrite the comparator, sort and append. Runtime O(nlogn)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        string res = "";
        vector<string> list;
        for (int i = 0; i < nums.size(); i++) list.push_back(to_string(nums[i]));
        sort(list.begin(), list.end(), [](string a, string b) {
            return (a + b) > (b + a);
        });
        
        for (int i = 0; i < list.size(); i++) res += list[i];
        return res.at(0) == '0' ? "0" : res;
    }
};

//Refactored way to write it
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        string res = "";
        vector<string> list;
        for (int i = 0; i < nums.size(); i++) list.push_back(to_string(nums[i]));
        sort(list.begin(), list.end(), comp);
        for (int i = 0; i < list.size(); i++) res += list[i];
        return res.at(0) == '0' ? "0" : res;
    }
    static bool comp(const string& a, const string& b) {
        return (a + b) > (b + a);
    }    

};
