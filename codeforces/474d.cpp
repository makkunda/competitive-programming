#include <iostream>
using namespace std;
#define mod 1000000007
int main()
{
	long long int a[100001];
	long long int presum[100001];
	long long int ans;
	long int t,k,i,a1,b;
	cin>>t>>k;
	a[0]=a[1]=1;
	presum[0]=1;
	for(i=2;i<k;i++)
		 {
		 	a[i]=1;
		 }
	for(i=k;i<=100000;i++)
	     {
	     	a[i] = (a[i-1] + a[i-k]) % mod;
	     	a[i] = (a[i] + mod) % mod;
	     }	 
	for(i=1;i<=100000;i++)
	   {
	   	presum[i] = (presum[i-1] + a[i])% mod;
	   	presum[i] = (presum[i] + mod) % mod;
	   }  
	for(i=0;i<t;i++)
	   {
	   	cin>>a1>>b;
	   	ans = presum[b] - presum[a1-1];
	   	ans = (ans + mod + mod) % mod;
	   	ans = (ans + mod) % mod;
	   	cout<<ans<<"\n";
	   }   
	  
}