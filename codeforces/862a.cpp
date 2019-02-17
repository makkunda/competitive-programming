#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,x,i;
	cin>>n>>x;
	vector<int> s;
	s.resize(n);
	int cnt;
	bool isp = false;
	vector<int> pres;
	pres.resize(101);
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		if(s[i]<x)
			cnt++;
		if(s[i]==x)
			isp = true;
		pres[s[i]]=1;
	}
	int mex = 101;
	int ans;
	for(i=0;i<101;i++)
	{
		if(pres[i]==0)
		{
			mex = i;
			break;
		}
	}
	if(mex>x)
		ans = 1;
	else
	{
		ans = 0;
		for(i=0;i<x;i++)
		{
			if(pres[i]==0)
				ans++;
		}
		if(pres[x]==1)
			ans++;
	}
	cout<<ans;
	return 0;
}