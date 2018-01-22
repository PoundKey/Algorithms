class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), compare);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            Interval& in = intervals[i];
            Interval last = res.back();
            if (in.start <= last.end) {
                last.end = max(last.end, in.end);
                res.pop_back();
                res.push_back(last);
            } else {
                res.push_back(in);
            }
        }
        return res;
    }
    
    static bool compare(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};
