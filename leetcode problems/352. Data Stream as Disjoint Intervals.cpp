/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        Interval cur(val,val);
        vector<Interval> temp;
        int insertPos = 0;
        for(Interval I:ranges){
            if(cur.end + 1 < I.start){
                temp.push_back(I);
            }else if(I.end+1 < cur.start){
                temp.push_back(I);
                insertPos++;
            }else{
                cur.start = min(cur.start,I.start);
                cur.end = max(cur.end,I.end);
            }
        }
        temp.insert(temp.begin()+insertPos,cur);
        ranges = temp;
    }

    vector<Interval> getIntervals() {
        return ranges;
    }
private:
    vector<Interval> ranges;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
