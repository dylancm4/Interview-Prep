//
//  MergeInvervals.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 
 You may assume that the intervals were initially sorted according to their start times.
 
 Example 1:
 
 Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].
 
 Example 2:
 
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
 
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 
 Make sure the returned intervals are also sorted.
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int num_intervals = intervals.size();
    vector<int> overlap_indices;
    for (int i = 0; i < num_intervals; i++)
    {
        bool overlap =
        max(newInterval.start, intervals[i].start) <=
        min(newInterval.end, intervals[i].end);
        if (overlap)
            overlap_indices.push_back(i);
    }
    if (overlap_indices.empty())
    {
        if (!num_intervals || newInterval.start > intervals[num_intervals-1].end)
        {
            intervals.insert(intervals.end(), newInterval);
        }
        else
        {
            for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); it++)
            {
                if (newInterval.end < it->start)
                {
                    intervals.insert(it, newInterval);
                    break;
                }
            }
        }
    }
    else
    {
        Interval merged_interval(
                                 min(intervals[overlap_indices.front()].start, newInterval.start),
                                 max(intervals[overlap_indices.back()].end, newInterval.end));
        
        vector<Interval>::iterator it_overlap_first = intervals.begin();
        vector<Interval>::iterator it_overlap_last = intervals.end();
        int i = 0;
        for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); it++)
        {
            if (i == overlap_indices.front())
                it_overlap_first = it;
            if (i == overlap_indices.back())
            {
                it_overlap_last = it;
                break;
            }
            i++;
        }
        vector<Interval>::iterator it = intervals.erase(it_overlap_first, it_overlap_last+1);
        intervals.insert(it, merged_interval);
    }
    return intervals;
}
