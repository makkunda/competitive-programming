#include <iostream>
#include <vector>
#include <string>
using namespace std;
string s;
string s_search;
#define lli long long int
lli MOD1 = 1000000007;
lli MOD2 = 1000000009;
lli p1 = 1000003;
lli p2 = 1000033;
// lli p1 = 31;
// lli p2 = 37;
lli p1_inv; // modulo MOD1
lli p2_inv; // modulo MOD2
lli n;
vector<lli> p1_pow;
// vector<lli> p1_inv_pow;
vector<lli> p2_pow;
// vector<lli> p2_inv_pow;
vector<lli> pre_suf_ind;
lli modsum(lli a,lli b,lli MOD)
{
	a = a % MOD;
	b = b % MOD;
	lli ans = (a+b)%MOD;
	ans = (ans + MOD)%MOD;
	return ans;
}
lli modmul(lli a,lli b,lli MOD)
{
	a = a % MOD;
	b = b % MOD;
	lli ans = (a*b)%MOD;
	ans = (ans + MOD)%MOD;
	return ans;
}
lli modpow(lli a,lli b,lli MOD)
{
	if(b==0)
		return 1;
	lli sqrt = modpow(a,b/2,MOD);
	lli ans = modmul(sqrt,sqrt,MOD);
	if(b%2)
	{
		ans = modmul(ans,a,MOD);
	}
	return ans;
}
lli get_hash1(string s)
{
	lli hash = 0;
	lli i;
	for(i=0;i<s.length();i++)
	{
		lli cur = (lli)((int)s[i] - (int)'a' + 1);
		lli curval = modmul(cur,p1_pow[i],MOD1);
		hash = modsum(hash,curval,MOD1);
	}
	return hash;
}

lli get_hash2(string s)
{
	lli hash = 0;
	lli i;
	for(i=0;i<s.length();i++)
	{
		lli cur = (lli)((int)s[i] - (int)'a' + 1);
		lli curval = modmul(cur,p2_pow[i],MOD2);
		hash = modsum(hash,curval,MOD2);
	}
	return hash;
}
bool check_substr(string in)
{
	// cout<<in<<endl;
	bool pos = false;
	lli h1 = get_hash1(in);
	// lli h2 = get_hash2(in);
	lli m = in.length();

	string initial = s_search.substr(0,(int)m);

	lli h1_r = get_hash1(initial);
	// lli h2_r = get_hash2(initial);
	// if(h1_r==h1 && h2_r==h2)
	// 	pos = true;
	if(h1_r==h1)
		pos = true;
	else
	{
		lli j;
		for(j=1;(j+m)<(n-1);j++)
		{
			lli rem_val = (lli)((int)s_search[j-1] - (int)'a' + 1);
			lli add_val = (lli)((int)s_search[j+m-1] - (int)'a' + 1);
			lli add_val_1 = modmul(add_val,p1_pow[m-1],MOD1);
			// lli add_val_2 = modmul(add_val,p2_pow[m-1],MOD2);
			h1_r = modsum(h1_r,-1*rem_val,MOD1);
			h1_r = modmul(h1_r,p1_inv,MOD1);
			h1_r = modsum(h1_r,add_val_1,MOD1);
			// h2_r = modsum(h2_r,-1*rem_val,MOD2);
			// h2_r = modmul(h2_r,p2_inv,MOD2);
			// h2_r = modsum(h2_r,add_val_2,MOD2);

			// if(h1_r==h1 && h2_r==h2){
			// 	pos = true;
			// 	break;
			// }

			if(h1_r==h1){
				pos = true;
				break;
			}
			// else
			// {
			// 	cout<<"starting at : "<<j<<endl;
			// 	if(h1_r!=h1)
			// 		cout<<h1<<" "<<h1_r<<" h1r not equal to h1"<<endl;
			// 	if(h2_r!=h2)
			// 		cout<<h2<<" "<<h2_r<<" h2r not equal to h2"<<endl;
			// }
		}
	} 
	return pos;
}
bool check_condition(lli len)
{
	// cout<<"Checking of Length "<<len<<endl;
	if(len==0){
		// cout<<"Result of Length "<<len<<" is true"<<endl;
		return true;
	}
	if(len>=n)
		return false;
	lli i;
	for(i=0;i<len;i++)
	{
		if(s[i]!=s[n-len+i]){
			// cout<<"Result of Length "<<len<<" is false due to start mismatch"<<endl;
			return false;
		}
	}
	string in_str = s.substr(0,len);
	if(check_substr(in_str)){
		// cout<<"Result of Length "<<len<<" is true"<<endl;
		return true;
	}
	// cout<<"Result of Length "<<len<<" is false due to substring not found"<<endl;
	return false;
}
void init()
{
	// cout<<modpow(2,10,MOD1)<<endl;
	p1_inv = modpow(p1,MOD1-2,MOD1);
	// p2_inv = modpow(p2,MOD2-2,MOD2);
	p1_pow.resize(n);
	// p2_pow.resize(n);
	// cout<<modmul(p1,p1_inv,MOD1)<<endl;
	// cout<<modmul(p2,p2_inv,MOD2)<<endl;
	// p1_inv_pow.resize(n);
	// p2_inv_pow.resize(n);
	p1_pow[0] = 1;
	// p2_pow[0] = 1;
	// p1_inv_pow[0] = 1;
	// p2_inv_pow[0] = 1;

	lli i;
	for(i=1;i<n;i++)
	{
		p1_pow[i] = modmul(p1_pow[i-1],p1,MOD1);
		// p2_pow[i] = modmul(p2_pow[i-1],p2,MOD2);
		// p1_inv_pow[i] = modmul(p1_inv_pow[i-1],p1_inv,MOD1);
		// p2_inv_pow[i] = modmul(p2_inv_pow[i-1],p2_inv,MOD2);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	n = (lli)s.length();
	if(n<3)
	{
		cout<<"Just a legend"<<'\n';
		return 0;
	}
	if(n==3)
	{
		if(s[0]!=s[1] || s[1]!=s[2])
			cout<<"Just a legend"<<'\n';
		else
			cout<<s[0]<<'\n';
		return 0;
	}
	lli i;
	bool check = true;
	for(i=0;i<n;i++)
	{
		if(s[i]!=s[0])
		{
			check = false;
			break;
		}
	}
	if(check)
	{
		for(i=0;i<(n-2);i++)
			cout<<s[i];
		return 0;
	}
	s_search = s.substr(1,(int)(n-1));
	s_search[n-2] = (char)((int)'a' + 27);
	// cout<<s_search<<endl;
	init();

	lli h1_pre = get_hash1(s.substr(0,1));
	// lli h2_pre = get_hash2(s.substr(0,1));

	lli h1_suf = get_hash1(s.substr(n-1,1));
	// lli h2_suf = get_hash2(s.substr(n-1,1));


	pre_suf_ind.push_back(0);
	// if(h1_pre==h1_suf && h2_pre==h2_suf)
	// 	pre_suf_ind.push_back(1);
	if(h1_pre==h1_suf)
		pre_suf_ind.push_back(1);
	for(i=1;i<(n-2);i++)
	{
		lli pre_add = (lli)((int)s[i] - (int)'a' + 1);
		lli pre_add_1 = modmul(pre_add,p1_pow[i],MOD1);
		// lli pre_add_2 = modmul(pre_add,p2_pow[i],MOD2);
		h1_pre = modsum(h1_pre,pre_add_1,MOD1);
		// h2_pre = modsum(h2_pre,pre_add_2,MOD2);

		h1_suf = modmul(h1_suf,p1,MOD1);
		// h2_suf = modmul(h2_suf,p2,MOD2);

		lli post_add = (lli)((int)s[n-i-1] - (int)'a' + 1);

		h1_suf = modsum(h1_suf,post_add,MOD1);
		// h2_suf = modsum(h2_suf,post_add,MOD2);

		// if(h1_pre==h1_suf && h2_pre==h2_suf)
		// 	pre_suf_ind.push_back(i+1);
		if(h1_pre==h1_suf)
			pre_suf_ind.push_back(i+1);
	}
	pre_suf_ind.push_back(n);

	lli lo = 0;
	lli hi = pre_suf_ind.size()-1;
	lli mid;

	while(lo<hi)
	{
		mid = lo + (hi-lo)/2;
		if(check_condition(pre_suf_ind[mid]))
			lo = mid + 1;
		else
			hi = mid;
	}
	if(lo==1)
		cout<<"Just a legend"<<'\n';
	else
	{
		for(i=0;i<pre_suf_ind[(lo-1)];i++)
			cout<<s[i];
		cout<<'\n';
	}
	return 0;
}
