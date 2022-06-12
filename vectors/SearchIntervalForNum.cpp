/**
given sorted, non-overlapped intervals find if a number is present or not
*/

#include <bits/stdc++.h>
using namespace std;

bool searchNumber(vector<vector<int>> &intervals, int q)
{
    int start = 0; 
    int end = intervals.size()-1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(intervals[mid][0] <= q && q < intervals[mid][1])
        {
            return true;
        }
        if(q < intervals[mid][0] )
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
	
	cout<<"Searching number 1 "<<searchNumber(intervals,1)<<endl;
	cout<<"Searching number 4 "<<searchNumber(intervals,4)<<endl;
	cout<<"Searching number 12 "<<searchNumber(intervals,12)<<endl;
  cout<<"Searching number 19 "<<searchNumber(intervals,19)<<endl;
	cout<<"Searching number 21 "<<searchNumber(intervals,21)<<endl;

	return 0;
}

