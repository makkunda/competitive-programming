#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> pre_a;
int find_pile(int q)
{
	int lo = 0;
	int hi = n-1;
	int mid ;
	while(lo<hi)
	{
		mid = lo + (hi-lo)/2;
		if(pre_a[mid]<q)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	vector<int> a;
	a.resize(n);
	pre_a.resize(n);
	int i,j;
	cin>>a[0];
	pre_a[0] = a[0];
	for(i=1;i<n;i++){
		cin>>a[i];
		pre_a[i] = pre_a[i-1] + a[i];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int cur_q;
		cin>>cur_q;
		int ans = find_pile(cur_q);
		cout<<ans+1<<'\n';
	}
	return 0;
}
