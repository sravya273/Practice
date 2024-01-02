/**

Given sorted, non-overlapping intervals and a new interval, check if the new interval overlaps with existing or not.

*/

#include <bits/stdc++.h>
using namespace std;

bool validInterval(vector<vector<int>> &intervals, vector<int>newInterval)
{
    int start = 0; 
    int end = intervals.size()-1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(newInterval[1] > intervals[mid][0]  && newInterval[0] < intervals[mid][1])
        {
            return false;
        }
        if(newInterval[0] < intervals[mid][0] )
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return true;
}


int main() {
	vector<vector<int>> intervals= {{1,3},{5,8},{10,11},{13,20}};
	cout<<"Intervals are {1,3},{5,8},{10,12},{13,20} "<<endl;
	cout<<"Searching {1,2} "<<validInterval(intervals,{1,2})<<endl;
	cout<<"Searching {1,3} "<<validInterval(intervals,{1,3})<<endl;
	cout<<"Searching {6,7} "<<validInterval(intervals,{6,7})<<endl;
  cout<<"Searching {11,12} "<<validInterval(intervals,{11,12})<<endl;
	cout<<"Searching {9,14} "<<validInterval(intervals,{9,14})<<endl;
	cout<<"Searching {21,24} "<<validInterval(intervals,{21,24})<<endl;


	return 0;
}
