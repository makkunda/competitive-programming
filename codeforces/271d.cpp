#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#define lli long long int
#define MOD1 1000000007
#define MOD2 1000000009
using namespace std;
lli p1 = 31;
lli p2 = 37;
lli p1_inv;
lli p2_inv;
vector<lli> p1_pow;
vector<lli> p2_pow;
vector<lli> p1_inv_pow;
vector<lli> p2_inv_pow;
vector<lli> hash1_pre;
vector<lli> hash2_pre;
string s;
lli modmul(lli a,lli b,lli MOD)
{
	a = a % MOD;
	b = b % MOD;
	lli ans = a*b;
	ans = ans % MOD;
	ans = (ans + MOD) % MOD;
	return ans;
}
lli modsum(lli a,lli b,lli MOD)
{
	a = a % MOD;
	b = b % MOD;
	lli ans = a+b;
	ans = ans % MOD;
	ans = (ans + MOD) % MOD;
	return ans;
}
lli modpow(lli a,lli b ,lli MOD)
{
	if(b==0)
		return 1;
	lli sqrt = modpow(a,b/2,MOD);
	lli ans = modmul(sqrt,sqrt,MOD);
	if(b%2)
		ans = modmul(ans,a,MOD);
	return ans;
}
pair<lli,lli> get_hash(int i,int j)
{
	lli hash1 = 0;
	lli hash2 = 0;
	if(i==0)
	{
		hash1 = hash1_pre[j];
		hash2 = hash2_pre[j];
	}
	else
	{
		hash1 = modsum(hash1_pre[j],-1*hash1_pre[i-1],MOD1);
		hash1 = modmul(hash1,p1_inv_pow[i],MOD1);

		hash2 = modsum(hash2_pre[j],-1*hash2_pre[i-1],MOD2);
		hash2 = modmul(hash2,p2_inv_pow[i],MOD2);

	}
	return make_pair(hash1,hash2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	string bad;
	cin>>bad;
	int k;
	cin>>k;
	int n = s.size();
	int i,j;

	p1_inv = modpow(p1,MOD1-2,MOD1);
	p2_inv = modpow(p2,MOD2-2,MOD2);

	// cout<<modmul(p1,p1_inv,MOD1)<<endl;
	// cout<<modmul(p2,p2_inv,MOD2)<<endl;

	p1_pow.resize(n);
	p2_pow.resize(n);
	p1_inv_pow.resize(n);
	p2_inv_pow.resize(n);
	p1_pow[0] = 1;
	p2_pow[0] = 1;
	p1_inv_pow[0] = 1;
	p2_inv_pow[0] = 1;
	hash1_pre.resize(n);
	hash2_pre.resize(n);

	hash1_pre[0] = (lli)(s[0]) - (lli)'a' + (lli)1;
	hash2_pre[0] = (lli)(s[0]) - (lli)'a' + (lli)1;

	for(i=1;i<n;i++)
	{
		p1_pow[i] = modmul(p1_pow[i-1],p1,MOD1);
		p2_pow[i] = modmul(p2_pow[i-1],p2,MOD2);
		p1_inv_pow[i] = modmul(p1_inv_pow[i-1],p1_inv,MOD1);
		p2_inv_pow[i] = modmul(p2_inv_pow[i-1],p2_inv,MOD2);

		lli curchar = (lli)(s[i]) - (lli)'a' + (lli)1;

		hash1_pre[i] = modsum(hash1_pre[i-1],modmul(curchar,p1_pow[i],MOD1),MOD1);
		hash2_pre[i] = modsum(hash2_pre[i-1],modmul(curchar,p2_pow[i],MOD2),MOD2);
	}



	vector<int> pre_sum;
	pre_sum.resize(n+1);
	for(i=1;i<=n;i++)
	{
		int chr = (int)(s[i-1]) - (int)'a';
		pre_sum[i] = pre_sum[i-1];
		if(bad[chr]=='0')
			pre_sum[i] += 1;
		// cout<<pre_sum[i]<<" ";
	}
	// cout<<'\n';
	set<pair<lli,lli> > uniq;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			int b_cnt = pre_sum[j] - pre_sum[i-1];
			if(b_cnt<=k){
				uniq.insert(get_hash(i-1,j-1));
				// cout<<i<<" "<<j<<" "<<(get_hash(i-1,j-1).first)<<" "<<(get_hash(i-1,j-1).second)<<endl;
			}
		}
	}
	int ans = uniq.size();
	cout<<ans<<'\n';
	return 0;
}
