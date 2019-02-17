#include <iostream>
using namespace std;
int ab(int x)
{
	if(x>0)
		return x;
	return -1*x;
}
int main()
{
	int x1,x2,y1,y2,x,y;
	cin>>x1>>y1>>x2>>y2>>x>>y;
	int x3 = ab(x1-x2);
	int y3 = ab(y1-y2);
	if((x3%x)!=0)
		cout<<"NO\n";
	else if((y3%y)!=0)
		cout<<"NO\n";
	else
	{
		int x4 = x3/x;
		int y4 = y3/y;
		if((x4-y4)%2==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}