#include <iostream>
using namespace std;
int main()
{
	long long int r,g,b,r1,g1,b1,rmod,gmod,bmod,ans,ans1;
	cin>>r>>g>>b;
	r1 = r/3;
	g1 = g/3;
	b1 = b/3;
	rmod = r%3;
	gmod = g%3;
	bmod = b%3;
	ans = r1 + g1 + b1;
	ans1 = rmod + gmod + bmod;
	if(ans1==6)
		ans = ans + 2;
	else if(ans1==5)
		ans = ans + 1;
	else if (ans1==4)
	{
		if(rmod==0){
			if(r1>0)
				ans = ans + 1;
		}
		else if(gmod==0){
			if(g1>0)
				ans = ans + 1;
		}
		else if(bmod==0){
			if(b1>0)
				ans = ans + 1;
		}
		else
			ans = ans + 1;
	}
	else if(ans1==3)
	{
		if(rmod==1 && gmod==1 && bmod==1)
			ans = ans + 1;
	}
	cout<<ans<<endl;
	// cout<<r1<<" "<<g1<<" "<<b1<<endl;
	// cout<<rmod<<" "<<gmod<<" "<<bmod<<endl;
	return 0;
}
