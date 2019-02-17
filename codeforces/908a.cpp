#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string s;
	int ans = 0;
	cin>>s;
	int n,i;
	n = s.length();
	for(i=0;i<n;i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			ans++;
		if(s[i]=='1'||s[i]=='3'||s[i]=='5'||s[i]=='7'||s[i]=='9')
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}