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
    static bool cmp(Interval a, Interval b){
        if (a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), cmp);
        int i = 0;
        while (i < intervals.size()){
            int p, q;
            p = intervals[i].start;
            q = intervals[i].end;
            while (i != intervals.size() - 1 && q >= intervals[i + 1]. start){
                q = max(q, intervals[i + 1].end);
                i ++;
            }
            ret.push_back(Interval(p, q));
            i ++;
        }
                return ret;
    }
};