#include <iostream>
#include <vector>

using namespace std;
vector<long long int> pre_a;
long long int n,t;
long long int max_far(int q)
{
	long long int lo = q;
	long long int hi = n+1;
	long long int mid;
	long long int ans;
	while(lo<hi)
	{
		mid = lo + (hi-lo)/2;
		if((pre_a[mid]-pre_a[q-1])<t)
			lo = mid + 1;
		else
			hi=mid;
	}
	if((pre_a[lo]-pre_a[q-1])==t)
		ans = lo+1-q;
	else
		ans = lo-q;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<long long int> a;
	cin>>n>>t;
	
	a.resize(n+2);
	pre_a.resize(n+2);
	long long int i,j;
	a[0] = 0;
	a[n+1] = 1000000001;
	for(i=1;i<=n;i++)
		cin>>a[i];
	pre_a[0]=a[0];
	for(i=1;i<=(n+1);i++)
	{
		pre_a[i] = pre_a[i-1] + a[i];
	}
	long long int ans = 0;
	for(i=1;i<=n;i++)
	{
		ans = max(ans,max_far(i));
	}
	cout<<ans<<endl;
	return 0;
}
