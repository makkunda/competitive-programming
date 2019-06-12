#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int l,n;
vector<int> a;
bool check_d(double d)
{
	if((double)a[0]>d)
		return false;
	if((((double)a[n-1]) + d) < (double)l)
		return false;
	int i;
	for(i=0;i<(n-1);i++)
	{
		double true_dist = (double)(a[i+1] - a[i]);
		double our_dist = 2.0*d;
		if(our_dist < true_dist)
			return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>l;
	a.resize(n);
	int i,j;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	double lo = 0.0;
	double hi = (double)l;
	double mid;
	int cnt = 0;
	while(cnt<100)
	{
		mid = lo + (hi-lo)/2;
		if (check_d(mid))
			hi = mid;
		else
			lo = mid;
		cnt = cnt + 1;
	}
	cout <<setprecision(15) << lo << '\n';
	return 0;
}
