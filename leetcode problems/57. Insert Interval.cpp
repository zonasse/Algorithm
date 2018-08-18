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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        int i = 0;
        while(i < intervals.size() && newInterval.start > intervals[i].end){
            ret.push_back(intervals[i++]);
        }
        while(i < intervals.size() &&  newInterval.end >= intervals[i].start){
            newInterval.start = min(newInterval.start,intervals[i].start);
            newInterval.end = max(newInterval.end,intervals[i].end);
            i++;
        }
        ret.push_back(newInterval);
        while(i < intervals.size()){
            ret.push_back(intervals[i++]);
        }
        return ret;
    }
};
