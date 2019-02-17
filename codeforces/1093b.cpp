#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		bool res = true;
		for(int i = 1;i<s.length();i++)
		{
			if(s[i]!=s[i-1])
				res = false;
		}
		if(res)
			cout<<-1<<endl;
		else
			cout<<s<<endl;
	}
	return 0;
}