#include <iostream>
using namespace std;
int main()
{
	long int n,i;
	cin>>n;
	long long int a[500002];
    long long int sum = 0;
    long long int fsum[500002],bsum[500002],ntime[500002];
	a[0]=a[n+1]=0;
	fsum[0]=0;bsum[n+1]=0;ntime[n+1]=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i+1];
		sum = sum + a[i+1];
		fsum[i+1] = sum;
	}
	if(sum%3!=0)
		cout<<0<<endl;
	else
	{
		long long int parsum = sum/3;
		for(i=n;i>=1;i--)
		{
			bsum[i]=bsum[i+1]+a[i];
			if(bsum[i]==parsum)
				  ntime[i]=ntime[i+1]+1;
			else
			      ntime[i]=ntime[i+1];	
		}
		long long int ans = 0;
		for(i=1;i<(n-1);i++)
			 {
			 	if(fsum[i]==parsum)
			 		 ans = ans + ntime[i+2];
			 }
		cout<<ans<<endl;	 
	}
	return 0;
}