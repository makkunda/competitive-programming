#include <iostream>
using namespace std;
long long int gcd(long long int a,long long int b)
 {
 	if(b == 0)
 		 return a;
 	return gcd(b,a%b);	
 }
 bool coprime(long long int a,long long int b)
   {
   	if(gcd(a,b)==1)
   		  return true;
   	return false;	
   }
long int mx(long int a,long int b)
  {
  	if(a>b)
  		return a;
  	return b;
  }   
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		long int n,i,j;
		long long int a[100000];
		long int count[100000];
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];count[i]=1;
		}
		for(i=1;i<n;i++)
		{
			long int temp = 0;
			for(j=i-1;j>=0;j--)
			{
				if(!coprime(a[i],a[j]))
				{
					//temp = mx(temp,count[j]);
					if(count[j]>temp)
						temp = count[j];
				}
			}
			count[i] = temp+1;
		}
		long int ans = 0;
		for(i=0;i<n;i++)
		{
			//ans = mx(ans,count[i]);
			if(count[i]>ans)
				  ans = count[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}