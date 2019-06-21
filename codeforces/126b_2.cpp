#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	int n;
	n = s.length();
	vector<int> z;
	z.resize(n);
	int l,r;
	l = -1;
	r = -1;
	int i,j,k;
	for(i=1;i<n;i++)
	{
		if(i>r)
		{
			for(j=0;(j+i)<n;j++)
			{
				if(s[j]==s[i+j])
					z[i] = z[i] + 1;
				else
					break;
			}
			l = i;
			r = i + z[i] - 1;
		}
		else
		{
			if(z[i-l]<(r-i+1))
				z[i] = z[i-l];
			else
			{
				z[i] = r - i + 1;
				for(j=1;(j+r)<n;j++)
				{
					if(s[r+j]==s[r-i+j])
						z[i] = z[i] + 1;
					else
						break;
				}
				l = i;
				r = i + z[i] - 1;
			}
		}
	}
	int ans = 0;
	int mxz = z[1];
	for(i=2;i<n;i++)
	{
		if(z[i]==(n-i) && (mxz>=(n-i)))
		{
			ans = i;
			break;
		}
		mxz = max(mxz,z[i]);
	}
	if(ans==0)
		cout<<"Just a legend"<<'\n';
	else
	{
		for(i=ans;i<n;i++)
			cout<<s[i];
		cout<<'\n';
	}
	return 0;
}
