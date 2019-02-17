#include <iostream>
using namespace std;
int main()
{
	int n,q,k;
	cin>>n>>q>>k;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int l_buc,r_buc;
		l_buc = l/k;
		r_buc = r/k;
		l_buc++;
		r_buc++;
		if(l%k==0)
			l_buc --;
		if(r%k==0)
			r_buc--;
		int red,yel;
		red = r_buc - l_buc - 1;
		red = max(red,0);
		if(r_buc == l_buc)
			yel = r - l + 1;
		else
		{
			yel = l_buc*k - l + 1 + r - (r_buc-1)*k ;
		}
		if(l%k==1)
		{
			if(l_buc!=r_buc)
			{
				yel = yel - k;
				red = red + 1;
			}
			else
			{
				if(r%k==0)
				{
					yel = 0;
					red = 1;
				}
			}
		}
		if(r%k==0)
		{
			if(l_buc!=r_buc)
			{
				yel = yel - k;
				red = red + 1;
			}
		}
		if(r==n && (r%k!=0))
		{
			if(l_buc!=r_buc)
			{
				yel = yel - (r%k);
				red = red + 1;
			}
			else
			{
				if(l%k==1)
				{
					yel = 0;
					red = 1;
				}
			}
		}
		cout<<yel<<" "<<red<<"\n";
	}
	return 0;
}