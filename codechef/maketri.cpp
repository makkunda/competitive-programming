#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long int 
using namespace std;
ll mx(ll a,ll b)
 {
 	if(a>b)
 		return a;
 	return b;
 }
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
 {
 	if(a.first<b.first)
 		  return true;
 	if(a.first>b.first)
 	      return false;
 	return (a.second < b.second);      	
 }
ll intersect(ll s1,ll e1,ll s2,ll e2)
 {
 	if(s1>e2 || s2>e1)
 		return 0;
 	if(s1<=s2 && e2<=e1)
 		return (e2 - s2 + 1);
 	if(s2<=s1 && e1<=e2)
 		return (e1 - s1 + 1);
 	if(s2<=s1)
 		return (e2 - s1 + 1);
 	return (e1 - s2 + 1);
 } 
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	long int n,i;
	cin>>n;
	long long int l,r;
	cin>>l>>r;
	vector<ll> a;
	a.resize(n);
	for(i=0;i<n;i++)
		 cin>>a[i];
	sort(a.begin(),a.end());
	vector<pair<ll,ll> > gap;
	ll left,right;
	for(i=0;i<(n-1);i++)
	 {
	 	left = a[i+1]-a[i]+1;
	 	right = a[i]+a[i+1]-1;
	 	pair<ll,ll> ab(left,right);
	 	gap.push_back(ab);
	 }	
	sort(gap.begin(),gap.end(),cmp);
	vector<pair<ll,ll> > gap1;
	gap1.push_back(gap[0]);
	long int siz = 1;
	for(i=1;i<(n-1);i++)
	 {
	 	if(gap[i].first>gap1[siz-1].second)
	 		  {
	 		  	gap1.push_back(gap[i]);
	 		  	siz++;
	 		  }
	    else
	     {
	     	gap1[siz-1].second = mx(gap[i].second,gap1[siz-1].second);
	     }		  
	 } 
	ll ans = 0; 
	for(i=0;i<siz;i++)
	{
		ans = ans + intersect(l,r,gap1[i].first,gap1[i].second);
	}
	cout<<ans<<"\n";
	return 0;
}