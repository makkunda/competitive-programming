#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
#define MOD 1000000007
long double ab(long double a)
{
	if(a>0)
		return a;
	return (-1*a);
}
int pa,pb;
long long int modpow(long long int  a, long long int b)
{
	long long int r = 1;
	while(b>0)
	{
		if((b%2)==1) 
		   r = (r*a)%MOD;
		a = (a*a)%MOD;
		b=b/2;
	}
	return r%MOD;
}
long long int modinv(long long int a)
	{
		return modpow(a,MOD-2);
	}

long long int modmul(long long int a,long long int b)
{
	a = a%MOD;
	b=b%MOD;
	long long int ans = a*b;
	ans = ans%MOD;
	ans = ans + MOD;
	ans = ans%MOD;
	return ans;
}

long long int modsum(long long int a,long long int b)
{
	a = a%MOD;
	b=b%MOD;
	long long int ans = a+b;
	ans = ans%MOD;
	ans = ans + MOD;
	ans = ans%MOD;
	return ans;
}

long long int addfracnum(long long int n1,long long int n2,long long int d1,long long int d2)
 {
 	long long int retnum = max(d1,d2);
 	if(retnum == d1)
 	{
 		long long int ans = n1;
 		long long int mult = modpow(modsum(pa,pb),d1-d2);
 		mult = modmul(mult,n2);
 		ans = modsum(ans,mult);
 		return ans;
 	}
 	else
 	{
 		long long int ans = n2;
 		long long int mult = modpow(modsum(pa,pb),d2-d1);
 		mult = modmul(mult,n1);
 		ans = modsum(ans,mult);
 		return ans;
 	}
 }

int main()
{
	int k;
	cin>>k>>pa>>pb;
	long long int dpn[2001][2001];
	long long int dpd[2001][2001];
	int i,j;
	for(i=0;i<=2000;i++)
	{
		for(j=0;j<=2000;j++)
			dpn[i][j]=dpd[i][j]=0;
	}
	dpn[1][0]=1;
	for(j=1;j<=k;j++)
	{
		dpn[1][j]=modmul(dpn[1][j-1],pb);
		dpd[1][j]=dpd[1][j-1]+1;
	}
	for(j=1;j<=k;j++)
	{
		for(i=1;i<=j;i++)
		{
			if((j%i)==0)
			{
			dpn[i][j]=modpow(pa,i);
			int n_j = j/i;
			long long int m2 = modpow(pb,n_j);
			dpn[i][j]=modmul(dpn[i][j],m2);
			dpd[i][j] = i+n_j;
			}
			
		} 
	}
	return 0;
}
