#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int n;
	// cin>>n;
	string s;
	cin>>s;
	n=s.length();
	vector<int> pre;
	pre.resize(n+1);
	int i;
	for(i=1;i<=n;i++)
	{
		if(s[i-1]=='A')
			pre[i]=pre[i-1]+1;
		else
			pre[i]=pre[i-1];
	}
	int j;
	int ans = 0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='Q')
		{
			for(j=i+1;j<n;j++)
			{
				if(s[j]=='Q')
					ans = ans + pre[j] - pre[i+1];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}