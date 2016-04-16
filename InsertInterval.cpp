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
        vector<Interval> res;
        int left,right;
        bool lr=0;
        bool ins=0;
        if (intervals.size()==0) {res.push_back(newInterval);return res;}
        for (int i=0;i<intervals.size();i++){
            if (ins==1) {res.push_back(intervals[i]);continue;}
            if (lr==0) {
                if (newInterval.start < intervals[i].start) {left=newInterval.start;lr=1;}
                else if (newInterval.start>=intervals[i].start && newInterval.start<=intervals[i].end) {
                    left=intervals[i].start;lr=1;
                }
                else res.push_back(intervals[i]);
                }
            if (lr==1) {
                if (newInterval.end<intervals[i].start) {
                    Interval Intv(left,newInterval.end);
                    res.push_back(Intv);
                    res.push_back(intervals[i]);
                    ins=1;
                }
                else if (newInterval.end>=intervals[i].start && newInterval.end<=intervals[i].end) {
                    Interval Intv(left,intervals[i].end);
                    res.push_back(Intv);
                    ins=1;
                }
                else continue;
            }
        }
        if (lr==0 && ins==0) res.push_back(newInterval);
        else if (lr==1 && ins==0) {Interval Intv(left,newInterval.end);res.push_back(Intv);}
        return res;
    }
};
