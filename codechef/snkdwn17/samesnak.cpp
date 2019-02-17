#include <iostream>
#define ll long long int
using namespace std;
// 1 is x same 2 is y same 3 is same point
int type(ll x1,ll y1,ll x2,ll y2)
{
	if(x1==x2 && y1==y2)
		return 3;
	if(x1==x2)
		return 1;
	return 2;
}
ll ab(ll n)
 {
 	if(n>0)
 		return n;
 	return -1*n;
 }

bool eq(pair<ll,ll> p1,pair<ll,ll> p2)
	{
		return ((p1.first==p2.first)&&(p1.second==p2.second));
	}

int main()
{
	long int t;
	cin>>t;
	while(t--)
	{
		bool ans = false;

		ll x11,x12,y11,y12;
		ll x21,x22,y21,y22;

		int t1,t2;

		cin>>x11>>y11>>x12>>y12;
		cin>>x21>>y21>>x22>>y22;

		t1 = type(x11,y11,x12,y12);
		t2 = type(x21,y21,x22,y22);

		if(t1==1)
		{
			if(y11>y12)
			{
				ll tmp = y11;
				y11 = y12;
				y12 = tmp;
			}
		}

		if(t2==1)
		{
			if(y21>y22)
			{
				ll tmp = y21;
				y21 = y22;
				y22 = tmp;
			}
		}

		if(t1==2)
		{
			if(x11>x12)
			{
				ll tmp = x11;
				x11 = x12;
				x12 = tmp;
			}
		}

		if(t2==2)
		{
			if(x21>x22)
			{
				ll tmp = x21;
				x21 = x22;
				x22 = tmp;
			}
		}

		pair<ll,ll> p11(x11,y11);
		pair<ll,ll> p12(x12,y12);
		pair<ll,ll> p21(x21,y21);
		pair<ll,ll> p22(x22,y22);

		if(t1==3 && t2 == 3)
		{
			if(eq(p11,p21))
				ans = true;
		/*	else if(x11==x21 && (ab(y11-y21)==1))
				ans = true;
			else if(y11==y21 && (ab(x11-x21)==1))
				ans = true; */
		}
		else if(t1==1 && t2==3)
		{
			if(x11==x21 && (y21>=y11) && (y21<=y12))
				ans = true;
		/*	else if(x11==x21 && y21==(y11-1))
				ans = true;
			else if(x11==x21 && y21==(y12+1))
				ans = true; */
		}

		else if(t1==3 && t2==1)
		{
			if(x11==x21 && (y11>=y21) && (y11<=y22))
				ans = true;
		/*	else if(x11==x21 && y11==(y21-1))
				ans = true;
			else if(x11==x21 && y11==(y22+1))
				ans = true; */
		}

		else if(t1==2 && t2==3)
		{
			if(y11==y21 && (x21>=x11) && (x21<=x12))
				ans = true;
		/*	else if(y11==y21 && x21==(x11-1))
				ans = true;
			else if(y11==y21 && x21==(x12+1))
				ans = true; */
		}

		else if(t1==3 && t2==2)
		{
			if(y11==y21 && (x11>=x21) && (x11<=x22))
				ans = true;
		/*	else if(y11==y21 && x11==(x21-1))
				ans = true;
			else if(y11==y21 && x11==(x22+1))
				ans = true; */
		}

		else if(t1==1 && t2==1)
		{
			if(x11!=x21)
				{ }
			else
			{
				if(y11>=y21 && y12<=y22)
					ans = true;
				else if(y21>=y11 && y22<=y12)
					ans = true;
				else if (y21>=y11 && y21<=y12)
					ans = true;
				else if(y11>=y21 && y11<=y22)
					ans = true;
			/*	else if (y11 ==(y22+1))
					ans = true;
				else if(y21==(y12+1))
					ans = true; */
			}
		}

		else if(t1==2 && t2==2)
		{
			if(y11!=y21)
				{ }
			else
			{
				if(x11>=x21 && x12<=x22)
					ans = true;
				else if(x21>=x11 && x22<=x12)
					ans = true;
				else if (x21>=x11 && x21<=x12)
					ans = true;
				else if(x11>=x21 && x11<=x22)
					ans = true;
			/*	else if (x11 ==(x22+1))
					ans = true;
				else if(x21==(x12+1))
					ans = true; */
			}
		}

		else if(t1==1 && t2==2)
		{
			if(eq(p11,p21)||eq(p11,p22)||eq(p12,p21)||eq(p12,p22))
				ans = true;
		/*	else if((x11 == (x21-1)) &&((y11==y21)||(y12==y21)))
				ans = true;
			else if((x11 == (x22+1)) &&((y11==y21)||(y12==y21)))
				ans = true;
			else if((x11 == (x21)) &&((y11==(y21+1))||(y12==(y21-1) )))
				ans = true;
			else if((x11 == (x22)) &&((y11==(y21+1))||(y12==(y21-1) )))
				ans = true; */
		}

		else 
		{
			if(eq(p11,p21)||eq(p11,p22)||eq(p12,p21)||eq(p12,p22))
				ans = true;
			/*else if((y11 == (y21-1)) &&((x11==x21)||(x12==x21)))
				ans = true;
			else if((y11 == (y22+1)) &&((x11==x21)||(x12==x21)))
				ans = true;
			else if((y11 == (y21)) &&((x11==(x21+1))||(x12==(x21-1) )))
				ans = true;
			else if((y11 == (y22)) &&((x11==(x21+1))||(x12==(x21-1) )))
				ans = true; */
		}

		if(ans)
			cout<<"yes\n";
		else 
			cout<<"no\n";
	}
	return 0;
}