#include <iostream>
using namespace std;
int main()
{
	int r,b,y;
	cin>>y>>b>>r;
	r = r-2;
	b = b-1;
	int mn = min(y,min(b,r));
	int ans = 3*mn + 3;
	cout<<ans<<endl;
	return 0;
}