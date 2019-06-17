#include <iostream>
#include <string>
using namespace std;
#define lli long long int
lli rb,rs,rc;
lli nb,ns,nc;
lli pb,ps,pc;
lli r;
bool check_pos(lli x)
{
	lli req_cost;
	lli zero = 0;
	lli req_b = x*rb;
	lli req_s = x*rs;
	lli req_c = x*rc;
	req_cost = max(zero,req_b-nb)*pb + max(zero,req_s-ns)*ps + max(zero,req_c-nc)*pc;
	// cout<<x<<" "<<req_cost<<" "<<r<<endl;
	if(req_cost>r)
		return true;
	return false;
}
int main()
{
	string burg;
	cin>>burg;
	int i;
	rb=0;
	rs=0;
	rc=0;
	for(i=0;i<burg.length();i++)
	{
		if(burg[i]=='B')
			rb++;
		else if(burg[i]=='S')
			rs++;
		else
			rc++;
	}
	cin>>nb>>ns>>nc;
	cin>>pb>>ps>>pc;
	cin>>r;
	lli lo = 0;
	lli hi = 10000000000000;
	lli mid;
	while(lo<hi)
	{
		mid = lo + (hi-lo)/2;
		if(check_pos(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	cout<<lo-1<<endl;
	return 0;
}
