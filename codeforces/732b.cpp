#include <iostream>
#include <algorithm>
using namespace std;
int mx(int a,int b)
 {
 	if(a>b)
 		return a;
 	return b;
 }
 int mn(int a,int b)
 {
 	if(a>b)
 		return b;
 	return a;
 }
int main()
{
	int n,k,i;
	int a[502];
	long int ans = 0;
	cin>>n>>k;
	a[0]=a[n+1]=k;
	for(i=1;i<=n;i++)
		{cin>>a[i];}
	for(i=1;i<=n;i++)
	{
		ans = ans + mx(k - a[i] - a[i-1],0);
		a[i] = mx(k - a[i] - a[i-1],0) + a[i];
	}


		cout<<ans<<endl;
		for(i=1;i<=n;i++)
			  cout<<a[i]<<" ";


	return 0;
}