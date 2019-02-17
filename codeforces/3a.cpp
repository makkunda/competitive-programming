#include <iostream>
using namespace std;
int main()
{
	int s,e;
	char s1,e1;
	cin>>s1>>s>>e1>>e;
	if(s1==e1)
	{
		if(s<=e)
		{
			cout<<(e-s)<<'\n';
			for(int i = s;i<e;i++)
				cout<<"U\n";
		}
		else
		{
			cout<<(s-e)<<'\n';
			for(int i = s;i>e;i--)
				cout<<"D\n";
		}
	}
	else if(s1<e1)
	{
		int r = (int)e1 - (int)s1;
		if(s<=e)
		{
			int c = e - s;
			int t = min(r,c);
			cout<<max(r,c)<<'\n';
			for(int i = 0;i<t;i++)
				cout<<"RU\n";
			if(r>t)
			{
				for(int i=t;i<r;i++)
					cout<<"R\n";
			}
			else
			{
				for(int i=t;i<c;i++)
					cout<<"U\n";
			}
		}
		else
		{
			int c = s - e;
			int t = min(r,c);
			cout<<max(r,c)<<'\n';
			for(int i = 0;i<t;i++)
				cout<<"RD\n";
			if(r>t)
			{
				for(int i=t;i<r;i++)
					cout<<"R\n";
			}
			else
			{
				for(int i=t;i<c;i++)
					cout<<"D\n";
			}
		}
	}

	else 
	{
		int r = (int)s1 - (int)e1;
		if(s<=e)
		{
			int c = e - s;
			int t = min(r,c);
			cout<<max(r,c)<<'\n';
			for(int i = 0;i<t;i++)
				cout<<"LU\n";
			if(r>t)
			{
				for(int i=t;i<r;i++)
					cout<<"L\n";
			}
			else
			{
				for(int i=t;i<c;i++)
					cout<<"U\n";
			}
		}
		else
		{
			int c = s - e;
			int t = min(r,c);
			cout<<max(r,c)<<'\n';
			for(int i = 0;i<t;i++)
				cout<<"LD\n";
			if(r>t)
			{
				for(int i=t;i<r;i++)
					cout<<"L\n";
			}
			else
			{
				for(int i=t;i<c;i++)
					cout<<"D\n";
			}
		}
	}
	return 0;
}