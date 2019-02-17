#include <iostream>
using namespace std;
int main()
{
	long int n,k,i;
	int a[150001];
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	long int ans = 1;
	int tempsum = 0;
	int minsum = 0;
	for(i=1;i<=k;i++)
		  tempsum = tempsum + a[i];
	minsum = tempsum;
	for(i=2;i<=(n-k+1);i++)
	      {
	      	tempsum = tempsum - a[i-1] + a[i+k-1];
	      	if(tempsum<minsum)
	      	     {ans = i;minsum = tempsum;} 
	      }	
	cout<<ans<<endl;      
	return 0;
}