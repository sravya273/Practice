// https://leetcode.com/problems/merge-intervals/

/**
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals 
that cover all the intervals in the input.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        
        for(auto interval:intervals)
        {
            if(ans.empty()  || ans.back()[1] < interval[0])
            {
                ans.push_back(interval);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1],interval[1]);
            }
        }
        return ans;
    }
};
