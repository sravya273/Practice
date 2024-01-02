// https://leetcode.com/problems/merge-intervals/

/**
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals 
that cover all the intervals in the input.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        if(n<=1)
        {
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end());
        
        int i=0;
        int j=1;
        
        while(i<n && j<n)
        {
            if(intervals[i][1]<intervals[j][0])
            {
                i++;
                intervals[i]=intervals[j];
                j++;
            }
            else
            {
                intervals[i][1] = max(intervals[i][1],intervals[j][1]);
                j++;
            }
        }
        intervals.resize(i+1);
        return intervals;
    }
};
