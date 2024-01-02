/**
Given sorted, non-overlapping intervals, check if an interval is in given list of intervals or not.
*/

#include <bits/stdc++.h>
using namespace std;

bool searchIntervals(vector<vector<int>> &intervals, vector<int>searchInterval)
{
    int start = 0; 
    int end = intervals.size()-1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;
        // cout<<" mid is "<<mid<<endl;
        if(intervals[mid][0] <= searchInterval[0] && searchInterval[1] <= intervals[mid][1])
        {
            return true;
        }
        if(searchInterval[1] < intervals[mid][0] )
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return false;
}


int main() {
	vector<vector<int>> intervals= {{1,3},{5,8},{10,12},{13,20}};
	cout<<"Intervals are {1,3},{5,8},{10,12},{13,20} "<<endl;
	cout<<"Searching {1,2} "<<searchIntervals(intervals,{1,2})<<endl;
	cout<<"Searching {1,3} "<<searchIntervals(intervals,{1,3})<<endl;
	cout<<"Searching {6,7} "<<searchIntervals(intervals,{6,7})<<endl;
    cout<<"Searching {11,12} "<<searchIntervals(intervals,{11,12})<<endl;
	cout<<"Searching {9,14} "<<searchIntervals(intervals,{9,14})<<endl;

	return 0;
}
