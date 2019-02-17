#include <iostream>
#include <vector>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	vector<long long int> req;
	req.resize(n+2);
	int i;
	for(i=1;i<=n;i++)
	{
		cin>>req[i];
	}
	vector<long long int> changeup;
	changeup.resize(n+2);
	changeup[0]=0;
	for(i=1;i<=n;i++)
	{
		if(req[i]>changeup[i-1])
			changeup[i]=req[i];
		else
			changeup[i]=changeup[i-1]+1;
	}
	vector<long long int> changedn;
	changedn.resize(n+2);
	changedn[n+1]=0;
	for(i=n;i>=1;i--)
	{
		if(req[i]>changedn[i+1])
			changedn[i]=req[i];
		else
			changedn[i]=changedn[i+1]+1;
	}
	vector<long long int> upextr;
	upextr.resize(n+2);
	for(i=1;i<=n;i++)
	{
		upextr[i]=upextr[i-1]+changeup[i]-req[i];
	}
	vector<long long int> dnextr;
	dnextr.resize(n+2);
	for(i=n;i>=1;i--)
	{
		dnextr[i]=dnextr[i+1]+changedn[i]-req[i];
	}
	long long int ans = min(dnextr[1],upextr[n]);
	for(i=1;i<=n;i++)
		{
			long long int temp = dnextr[i] + upextr[i] - min(changeup[i],changedn[i])+req[i] ;
			ans = min(ans,temp);
		}
	cout<<ans<<endl;
	return 0;
}