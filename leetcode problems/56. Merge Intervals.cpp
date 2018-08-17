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
        vector<Interval> ret;
        if(intervals.empty()) return ret;
        sort(intervals.begin(),intervals.end(),cmp);
        ret.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); ++i){
            if(ret.back().end < intervals[i].start){
                ret.push_back(intervals[i]);
            }else{
                ret.back().end = max(ret.back().end,intervals[i].end);
            }
        }
        return ret;
    }
    static const bool cmp(const Interval &T1,const Interval &T2){
        return T1.start <T2.start;
    }
};
