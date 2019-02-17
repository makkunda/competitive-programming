#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	long long int n,k;
	cin>>n>>k;
	vector<long long int> prime;
	vector<bool> isp;
	long long int i,j;
	isp.resize(n+1);
	for(i=0;i<=n;i++)
		isp[i]=true;
	for(i=2;i<=n;i++)
	{
		if(isp[i])
		{
			for(j=i*i;j<=n;j=j+i)
				isp[j]=false;
		}
	}
	for(i=2;i<=n;i++)
	{
		if(isp[i])
			prime.push_back(i);
	}
	vector<long long int> fact;
	for(i=0;i<(prime.size());i++)
	{
		if(n%prime[i]==0)
		{
			while(n%prime[i]==0)
			{
				fact.push_back(prime[i]);
				n = n/prime[i];
			}
		}
	}
	if(fact.size()<k)
		cout<<"-1\n";
	else
	{
		int temp = 1;
		for(i=(k-1);i<fact.size();i++)
			temp = temp*fact[i];
		for(i=0;i<(k-1);i++)
			cout<<fact[i]<<" ";
		cout<<temp<<"\n";
	}
	return 0;
}