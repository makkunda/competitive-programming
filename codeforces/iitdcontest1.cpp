#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,sum=0,minsum;
	int a[100];
	cin>>n;
	for(i=0;i<n;i++)
	   {
	    cin>>a[i];
	    sum = sum + a[i];
	   }
	sort(a,a+n);
	minsum = sum/2;
	minsum = minsum + 1;
	int cursum = 0;
	int count = 0;
	for(i=n-1;i>=0;i--)
	 {
	 	count++;
	 	cursum = cursum + a[i];
	 	if(cursum>=minsum)
	 	     break;
	 }
	 cout<<count; 
}