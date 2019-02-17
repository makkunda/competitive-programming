#include <iostream>
#include <vector>
using namespace std;
int main()
{
	cin.tie(0);ios::sync_with_stdio(false);
	vector<int> nfact;
	nfact.resize(5000001);
	vector<int> isp;
	isp.resize(5000001);
	long long int i,j;
	for(i=2;i<=5000000;i++)
	{
		if(isp[i]==0)
		{
			nfact[i]=1;
			isp[i]=i;
			for(j=i*i;j<=5000000;j=j+i)
			{
				if(isp[j]==0)
				{
					isp[j]=i;
				}
			}
		}
	}
	for(i=2;i<=5000000;i++)
	{
		nfact[i]=nfact[i/isp[i]]+1;
	}
	vector<long long int> cumul;
	cumul.resize(5000001);
	for(i=1;i<=5000000;i++)
	{
		cumul[i]=cumul[i-1]+nfact[i];
	}
	long long int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		long long int ans = cumul[a]-cumul[b];
		//cout<<cumul[a]<<" "<<cumul[b]<<"\n";
		cout<<ans<<'\n';
	}
	return 0;
}