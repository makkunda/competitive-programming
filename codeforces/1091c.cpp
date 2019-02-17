#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	long long int sqrtn = (long long int)sqrt(n) + 1;
	long long int i;
	vector<long long int> divisors;
	for(i=1;i<=sqrtn;i++)
	{
		if(n%i==0)
		{
			divisors.push_back(i);
			divisors.push_back(n/i);
		}
	}
	sort(divisors.begin(),divisors.end());
	vector<long long int> corr_divisors;
	corr_divisors.push_back(divisors[0]);
	int sz = 1;
	for(i=1;i<divisors.size();i++)
	{
		if(divisors[i]!=corr_divisors[sz-1])
		{
			corr_divisors.push_back(divisors[i]);
			sz++;
		}
	}
	vector<long long int> ans;
	for(i=0;i<corr_divisors.size();i++)
	{
		long long int cur = corr_divisors[i];
		long long int n_terms = (n/cur + 1);
		long long int temp_ans = n_terms*(n+2);
		temp_ans = temp_ans/2;
		temp_ans = temp_ans - n - 1;
		ans.push_back(temp_ans);
	}
	sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}