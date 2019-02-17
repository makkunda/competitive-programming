#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int i,j,k,l;
	cin>>s;
	int n = s.size();
	bool done = false;
	int ans ;
	for(i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			ans  = 0;
			done = true;
			break;
		}
		else if(s[i]=='8')
		{
			ans = 8;
			done = true;
			break;
		}
	}
	if(!done)
	{
		int d1,d2;
		char cd1,cd2;
		for(i=16;i<=96;i=i+8)
		{
			d2 = i%10;
			d1 = i/10;
			cd1 = (char)(d1  + ((int)'0'));
			cd2 = (char)(d2  + ((int)'0'));
			for(j=0;j<n;j++)
			{
				if(s[j]==cd1)
				{
					for(k=j+1;k<n;k++)
					{
						if(s[k]==cd2)
						{
							ans = i;
							done = true;
							j = n;
							break;
						}
					}
				}

			}
		}
	}
	if(!done)
	{
		int d1,d2,d3,temp;
		char cd1,cd2,cd3;
		for(i=104;i<=992;i=i+8)
		{
			temp = i;
			d3 = i%10;
			temp = temp/10;
			d2 = temp%10;
			d1 = temp/10;
			cd1 = (char)(d1 + ((int)'0'));
			cd2 = (char)(d2 + ((int)'0'));
			cd3 = (char)(d3 + ((int)'0'));
			for(j=0;j<n;j++)
			{
				if(s[j]==cd1)
				{
					for(k=j+1;k<n;k++)
					{
						if(s[k]==cd2)
						{
							for(l = k+1;l<n;l++)
							{
								if(s[l]==cd3)
								{
									done = true;
									ans = i;
									k = n;
									j = n;
									break;
								}
							}
						}
					}
				}

			}
		}
	}
	if(done)
	{
		cout<<"YES\n"<<ans<<"\n";
	}
	else
		cout<<"NO\n";
	return 0;
}
