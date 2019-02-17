#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> prime;
	vector<bool> isp;
	int i,j;
	int count = 0;
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
	for(i=0;i<(prime.size()-1);i++)
	{
		int l = prime[i] + prime[i+1] + 1;
		if(binary_search(prime.begin(),prime.end(),l))
			count++;
	}
	if(count>=k)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}