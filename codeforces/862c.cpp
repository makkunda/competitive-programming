#include <iostream>
using namespace std;
int main()
{
	int n,x;
	cin>>n>>x;
	if(x==0 && n==2)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	int l = n%4;
	int i;
	if(x==0)
	{
		if(n==1)
			cout<<0;
		else if(n==3)
			cout<<"1 2 3";
		else if(n==4)
			cout<<"0 1 2 3";
		else if(l==3)
		{
			int i ;
			for(i=1;i<=n;i++)
				cout<<i<<" ";
		}
		else if(l==0)
		{
			int i;
			for(i=0;i<n;i++)
				cout<<i<<" ";
		}
		else if(l==1)
		{
			for(i=1;i<=(n-4);i++)
				cout<<i<<" ";
			cout<<(n-3 + 262144)<<" ";
			cout<<(n-2 + 524288)<<" ";
			cout<<"262144 524288";
		}
		else
		{
			for(i=0;i<(n-4);i++)
				cout<<i<<" ";
			cout<<(n-4 + 262144)<<" ";
			cout<<(n-3 + 524288)<<" ";
			cout<<"262144 524288";
		}
		return 0;
	}
	if(n==1)
	{
		cout<<x;
		return 0;
	}
	if(n==2)
	{
		cout<<x<<" 0";
		return 0;
	}
	if(n==3)
	{
		cout<<262144+x<<" "<<262144<<" "<<0;
		return 0;
	}
	if(n==4)
	{
		if(x==1)
			cout<<"5 7 9 10";
		else if(x==2)
			cout<<"6 7 9 10";
		else if(x==3)
			cout<<"5 7 10 11";
		else
			cout<<262144+x<<" "<<262144+3<<" "<<524288+1<<" "<<524288+2;
		return 0;
	}
	if(l==0)
	{
		int i;
		cout<<0<<" ";
		for(i=3;i<=(n-3);i++)
			cout<<i<<" ";
		cout<<262144<<" ";
		cout<<262144+x<<" ";
		cout<<524288<<" ";
		cout<<524288+2<<" ";
	}
	else if(l==1)
	{
		int i;
		for(i=1;i<=(n-2);i++)
			cout<<i<<" ";
		cout<<262144<<" ";
		cout<<262144+x<<" ";
	}
	else if(l==2)
	{
		int i;
		for(i=2;i<=(n-1);i++)
			cout<<i<<" ";
		cout<<262144<<" ";
		cout<<262144+x<<" ";
	}
	else if(l==3)
	{
		int i;
		for(i=3;i<=(n-2);i++)
			cout<<i<<" ";
		cout<<262144<<" ";
		cout<<262144+x<<" ";
		cout<<524288<<" ";
		cout<<524288+2<<" ";
	}
	return 0;
}

