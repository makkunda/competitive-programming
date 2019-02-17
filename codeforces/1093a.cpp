#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		int ans;
		if(x<=7)
			ans = 1;
		else if(x%7==0)
			ans = x/7;
		else
		{
			ans = (x/7) + 1;
		}
		cout<<ans<<endl;
	}
	return 0;
}