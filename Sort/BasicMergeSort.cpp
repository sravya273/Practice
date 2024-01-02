#include <bits/stdc++.h>
using namespace std;

void merge(vector <int> &arr, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    vector<int>aux1(n1);
    vector<int>aux2(n2);
    for(int i=0;i<n1;i++)
    {
        aux1[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        aux2[j]= arr[m+1+j];
    }
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (aux1[i] <= aux2[j]) {
            arr[k] = aux1[i];
            i++;
        }
        else {
            arr[k] = aux2[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        arr[k] = aux1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = aux2[j];
        j++;
        k++;
    }
}
void merge_sort(vector <int> &arr, int left,int right)
{
    if(right>left){
        int mid =(left+right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
void print_vector(vector <int>arr, int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
int main() {
	int n;
	cin>>n;
	vector <int> arr;
	int input;
	for(int i=0;i<n;i++)
	{
	    cin>>input;
	    arr.push_back(input);
	}
	print_vector(arr,n);
	merge_sort(arr,0,n-1);
	print_vector(arr,n);
	return 0;
}
