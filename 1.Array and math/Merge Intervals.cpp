/*
Merge Intervals

Problem Description

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.



Problem Constraints
1 <= |intervals| <= 105



Input Format
First argument is the vector of intervals

second argument is the new interval to be merged



Output Format
Return the vector of intervals after merging



Example Input
Input 1:

Given intervals [1, 3], [6, 9] insert and merge [2, 5] .
Input 2:

Given intervals [1, 3], [6, 9] insert and merge [2, 6] .


Example Output
Output 1:

 [ [1, 5], [6, 9] ]
Output 2:

 [ [1, 9] ]


Example Explanation
Explanation 1:

(2,5) does not completely merge the given intervals
Explanation 2:

(2,6) completely merges the given intervals

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

	int i;
	int n = intervals.size();
	vector<Interval> final;
	// if both start and end is less than newInterval
	// push it to final
	for (i = 0; i < n; i++) {
		if (intervals[i].start < newInterval.start and intervals[i].end < newInterval.start) {
			final.push_back(intervals[i]);
		} else {
			break;
		}
	}

	// now try to merge if possible

	Interval x;
	if (i != n and intervals[i].start < newInterval.start) {
		x.start = intervals[i].start;
	} else if (i != n) {
		x.start = newInterval.start;
	}

	if (i == n) {
		x.start = newInterval.start;
		x.end = newInterval.end;
	}

	bool merged = false;
	while (i < n) {
		if (newInterval.end >= intervals[i].start and newInterval.end < intervals[i].end) {
			x.end = intervals[i].end;
			i++;
			merged = true;
			break;
		} else if (newInterval.end < intervals[i].start) {
			x.end = newInterval.end;
			merged = true;
			break;
		}
		i++;
	}

	if (!merged) {
		x.end = newInterval.end;
	}

	// merging is done
	final.push_back(x);
	while (i < n) {
		final.push_back(intervals[i]);
		i++;
	}

	return final;

}
