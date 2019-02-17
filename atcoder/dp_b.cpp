#include <iostream>
#include <vector>
using namespace std;
int ab(int x)
{
	if(x<0)
		return -1*x;
	return x;
}
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> h;
	h.resize(n+1);
	int i,j;
	h[0] = -1000000;
	for(i=1;i<=n;i++)
		cin>>h[i];
	vector<int> mincost;
	mincost.resize(n+1);
	mincost[0] = 0;
	mincost[1] = 0;
	for(i=2;i<=n;i++)
	{
		mincost[i] = mincost[i-1] + ab(h[i]-h[i-1]);
		for(j=i-2;j>=max(i-k,0);j--)
			mincost[i] = min(mincost[i],mincost[j] + ab(h[i]-h[j]));
	}
	cout<<mincost[n]<<endl;
	return 0;
}