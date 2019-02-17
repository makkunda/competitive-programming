#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int v;
	vector<int> a;
	a.resize(10);
	int i;
	cin>>v;
	for(i=1;i<=9;i++)
		cin>>a[i];
	int dig = v/a[9];
	int cur = 9;
	int nd;
	for(i=8;i>=1;i--)
	{
		nd = v/a[i];
		if(nd>=dig)
		{
			if(a[i]<a[cur]){
			dig = nd;
			cur = i;
		}
		}
	}
	vector<int> ans;
	for(i=0;i<dig;i++)
		ans.push_back(cur);
	v = v - a[cur]*dig;
	int n = 0;
	int ccost = a[cur];
	while(v>0)
	{
		bool change = false;
		for(i=9;i>cur;i--)
		{
			int ncost = a[i]-ccost;
			if(ncost<=v)
			{
				v = v - ncost;
				ans[n] = i;
				n=n+1;
				change = true;
				break;
			}
		}
		if(!change)
			break;
	}
	for(i=0;i<ans.size();i++)
		cout<<ans[i];
	if(ans.size()==0)
		cout<<"-1";
	cout<<'\n';
	return 0;
}