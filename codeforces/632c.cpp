#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool custom_comp(string a,string b)
{
	string fs = a + b;
	string snd = b + a;
	return (fs<snd);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<string> a;
	int n;
	cin>>n;
	int i;
	string x;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end(),custom_comp);
	string ans = "";
	for(i=0;i<n;i++)
		ans += a[i];
	cout<<ans<<endl;
	return 0;
}
