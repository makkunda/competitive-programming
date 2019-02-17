#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	char mz[50][50];
	int sx,sy;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>mz[i][j];
			if(mz[i][j]=='S')
			{
				sx=i;sy=j;
			}
		}
	}
	string s;
	cin>>s;
	char a,b,c,d;
	int cnt = 0;
	for(a='0';a<='3';a++)
	{
		for(b='0';b<='3';b++)
		{
			if(b!=a)
			{
				for(c='0';c<='3';c++)
				{
					if(c!=a&&c!=b)
					{
						for(d='0';d<='3';d++)
						{
							if(d!=a&&d!=b&&d!=c)
							{
								// cout<<(cnt)<<" "<<a<<b<<c<<d<<endl;
								bool pos = true;
								int curx=sx,cury=sy;
								for(i=0;i<s.length();i++)
								{
									if((curx<0)||(curx>=n)||(cury<0)||(cury>=m))
									{
										pos = false;
										break;
									}
									else if(mz[curx][cury]=='E')
										break;
									else if(mz[curx][cury]=='#')
									{
										pos = false;
										break;
									}
									else
									{
										if(s[i]==a)
											curx++;
										if(s[i]==b)
											cury++;
										if(s[i]==c)
											curx--;
										if(s[i]==d)
											cury--;
									}
								}

								if((curx<0)||(curx>=n)||(cury<0)||(cury>=m))
									{
										pos = false;
									}
								else if(mz[curx][cury]!='E')
										pos = false;

								if(pos)
									cnt++;
							}
						}
					}
				}
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}