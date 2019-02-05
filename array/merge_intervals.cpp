#include "./../lc.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}   
};

bool cmp(const Interval &interval1, const Interval &interval2) {
    return interval1.start < interval2.start;
}

vector<Interval> solution(vector<Interval> &intervals) {
    if(intervals.size() <= 1)
        return intervals;

    sort(intervals.begin(), intervals.end(), cmp);
    int start = intervals[0].start;
    int end = intervals[0].end;
    vector<Interval> result;
    for(vector<Interval>::const_iterator it = intervals.cbegin() + 1; it != intervals.cend(); it++) {
        if(it->start <= end)        // overlapping intervals
            end = max(end, it->end);
        else {
            result.push_back(Interval(start, end));
            start = it->start;
            end = it->end;
        }
    }
    result.push_back(Interval(start, end));     // add the last interval
    return result;
}

int main(int argc, char **argv) {
    vector<Interval> nums1 = {
        {1,3},{2,6},{8,10},{15,18}
    };
    vector<Interval> res1 = solution(nums1);
    vector<Interval> nums2 = {
        {1,4},{4,5}
    };
    vector<Interval> res2 = solution(nums2);
    
    std::cout << "done.";
    return 0;
}