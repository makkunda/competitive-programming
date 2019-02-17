#include <iostream>
#include <vector>
#define lli long long int
using namespace std;
int main()
{
	lli n;
	cin>>n;
	if(n<6)
		cout<<0;
	else
	{
		vector<int> prime;
		prime.push_back(2);prime.push_back(3);prime.push_back(5);
		int i,j;
		for(i=7;i<=n;i=i+2)
			{
				bool isp = true;
				for(j=0;j<prime.size();j++)
				{
					if(i%prime[j]==0)
					{
						isp=false;
						break;
					}
				}
				if(isp)
					prime.push_back(i);
			}
		int sz = prime.size();
		vector<int> freq;
		freq.resize(n+1);
		for(i=6;i<=n;i++)
		{
			for(j=0;j<sz;j++)
			{
				if(i%prime[j]==0)
					freq[i]++;
			}
		}
		int ans = 0;
		for(i=6;i<=n;i++)
		{
			// cout<<i<<" "<<freq[i]<<endl;
			if(freq[i]==2)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}