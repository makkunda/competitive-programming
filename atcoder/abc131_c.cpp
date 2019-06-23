#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define lli long long int
#define pb push_back
using namespace std;
lli gcd(lli a,lli b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	lli a,b,c,d;
	cin>>a>>b>>c>>d;
	lli gc = gcd(c,d);
	lli lc = c*d;
	lc = lc/gc;
	lli cnt_till_a_c = (a-1)/c;
	lli cnt_till_a_d = (a-1)/d;
	lli cnt_till_a_lc = (a-1)/lc;

	lli cnt_till_b_c = b/c;
	lli cnt_till_b_d = b/d;
	lli cnt_till_b_lc = b/lc;

	lli n_c = cnt_till_b_c - cnt_till_a_c;
	lli n_d = cnt_till_b_d - cnt_till_a_d;
	lli n_lc = cnt_till_b_lc - cnt_till_a_lc;

	lli ans = n_c + n_d - n_lc;

	ans = b - (a-1) - ans;

	cout<<ans<<endl;


	return 0;
}
