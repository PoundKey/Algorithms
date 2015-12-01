// Thoughts: Overrite the comparator, sort using interval.start.
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size(), i = 1;
        res.push_back(intervals[0]);
        while (i < n) {
            if (res.back().end >= intervals[i].start) {
                res.back().end = max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
            i++;
        }
        return res;
    }
    static bool compare(const Interval& v1, const Interval& v2) {
        return v1.start < v2.start;
    }
};