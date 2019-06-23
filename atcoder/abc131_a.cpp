#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define lli long long int
#define pb push_back
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	int i;
	bool bad = false;
	for(i=0;i<3;i++)
	{
		if(s[i]==s[i+1])
		{
			bad = true;
			break;
		}
	}
	if(bad)
		cout<<"Bad"<<endl;
	else
		cout<<"Good"<<endl;
	return 0;
}
