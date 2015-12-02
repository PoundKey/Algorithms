// Thoughts: Code borrowed from Q57, can we do better...? Yeah.
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
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

// Thoughts: Use Index 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res = intervals;
        int i = 0, overlap = 0, n = res.size();
        while (i < n) {
            if (newInterval.end < res[i].start) break;  
            else if (newInterval.start <= res[i].end) {
                newInterval.start = min(newInterval.start, res[i].start);
                newInterval.end = max(newInterval.end, res[i].end);
                overlap++;
            }
            i++;
        }
        if (overlap > 0) res.erase(res.begin() + i - overlap, res.begin() + i);
        res.insert(res.begin() + i - overlap, newInterval);
        return res;
    }
};
