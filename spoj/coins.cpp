#include <iostream>
#include <vector>
#include <map>
#include <utility>
#define lli long long int
using namespace std;
vector<long long int> dp;
map<lli,lli> dp1;
map<lli,lli>::iterator it;
lli mx(lli a,lli b)
 {
 	if(a>b)
 	   return a;
 	return b;   
 }
lli dpf(lli a)
 {
 	it = dp1.find(a);
 	if(it!=dp1.end())
 		  return it->second;
 	else
 	 {
 	 	if(a<12)
 	 	{
 	 		dp1.insert(pair<lli,lli>(a,a));
 	 		return a;
 	 	}
 	 	else
 	 	{
 	 		lli a1,a2,a3;
 	 		a1=a/2;a2=a/3;a3=a/4;
 	 		lli f1,f2,f3;
 	 		f1 = dpf(a3);
 	 		f2=dpf(a2);
 	 		f3 = dpf(a1);
 	 		lli tt = mx(a,f1+f2+f3);
 	 		dp1.insert(pair<lli,lli>(a,tt));
 	 		return tt;
 	 	}
 	 }	
 } 
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	long long int n;
	while(cin>>n)
	{
		lli ans = dpf(n);
		cout<<ans<<"\n";
	}
	return 0;
}