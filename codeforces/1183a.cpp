#include <iostream>
using namespace std;
int digsum(int x)
{
	int ans = 0;
	while(x)
	{
		ans = ans + (x%10);
		x = x/10;
	}
	return ans;
}
int main()
{
	int a;
	cin>>a;
	if(digsum(a)%4==0)
		cout<<a<<endl;
	else if(digsum(a+1)%4==0)
		cout<<(a+1)<<endl;
	else if(digsum(a+2)%4==0)
		cout<<(a+2)<<endl;
	else if(digsum(a+3)%4==0)
		cout<<(a+3)<<endl;
	else if(digsum(a+4)%4==0)
		cout<<(a+4)<<endl;
	else if(digsum(a+5)%4==0)
		cout<<(a+5)<<endl;
	else if(digsum(a+6)%4==0)
		cout<<(a+6)<<endl;
	else if(digsum(a+7)%4==0)
		cout<<(a+7)<<endl;
	return 0;
}
