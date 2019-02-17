#include <iostream>
#define lli long long int
using namespace std;
int main()
{
	lli n;
	cin>>n;
	if(n==1||n==2)
		cout<<-1;
	else
	{
		if(n%2)
		{
			lli r,s;
			r = (n+1)/2;
			s = r - 1;
			lli y,z;
			y = 2*r*s;
			z = r*r + s*s;
			cout<<y<<" "<<z;
		}
		else
		{
			lli temp = n;
			while(temp%2==0)
			{
				temp = temp/2;
			}
			if(temp==1)
			{
				lli diff = n/4;
				lli y,z;
				y = 3*diff;
				z = 5*diff;
				cout<<y<<" "<<z;
			}
			else
			{
				lli diff = n/temp;
				lli r,s;
				r = (temp+1)/2;
				s = r - 1;
				lli y,z;
				y = 2*r*s;
				z = r*r + s*s;
				y =y*diff;
				z = z*diff;
				cout<<y<<" "<<z;

			}
		}
	}
	return 0;
}