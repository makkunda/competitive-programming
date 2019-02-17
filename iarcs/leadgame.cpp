#include <iostream>
using namespace std;

int main()
{
	int n,i;
	cin>>n;
	int lead = 0,l1,r1,temp,l=0,r=0;
	int ans = 1;
	for(i=0;i<n;i++)
	{
		cin>>l1>>r1;
		l = l + l1;
		r = r + r1;
		if(l>r)
		  {
		  temp = l-r;
		  if(temp>lead)
		     {
		     lead = temp;
		     ans = 1;
		     }
		  }
		  else if(l<r)
		  {
		  temp = r - l;
		  if(temp>lead)
		     {
		     lead = temp;
		     ans = 2;
		     }
		  }
	}
	cout<<ans<<" "<<lead;
	return 0;
}