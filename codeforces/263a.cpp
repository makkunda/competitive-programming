#include <iostream>
using namespace std;
int abs(int x)
{
	if(x>0)
		return x;
	else
		return -1*x;
}
int main()
{
	int i,j,x;
	for(int i1=0;i1<5;i1++)
	{
		for(int i2=0;i2<5;i2++)
		{
			cin>>x;
			if(x)
			{
				i=i1;
				j=i2;
			}
		}
	}
	int ans=abs(i-2) + abs(j-2) ;
	cout<<ans;
	return 0;
}