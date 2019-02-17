#include <iostream>
using namespace std;
#define mod 1000000007
int main(){
long long int a[101],b[101];
int n,d,k,i,j;
a[0]=b[0]=1;
cin>>n>>k>>d;
int t = d - 1;
for(i=1;i<=n;i++)
{
	long long int temp = 0;
	for(j=k;j>0;j--)
	{
		if((i-j)>=0)
			 {
			 	temp = (temp + a[i-j])%mod;
			 	temp = (temp + mod)%mod;
			 }
	}
	a[i] = temp;
}
if(d==1)
    cout<<a[n]<<"\n";
else
{
	for(i=1;i<=n;i++)
{
	long long int temp = 0;
	for(j=t;j>0;j--)
	{
		if((i-j)>=0)
			 {
			 	temp = (temp + b[i-j])%mod;
			 	temp = (temp + mod)%mod;
			 }
	}
	b[i] = temp;
}
long long int ans = a[n] - b[n];
ans = (ans + mod)%mod;
ans = (ans + mod)%mod;
cout<<ans<<"\n"
}
return 0;
}