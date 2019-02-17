#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n,m,kk,i,j;
	char a[500][500];
	cin>>n>>m>>kk;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cin>>a[i][j];
	}
	queue<int> q;
	int count1 = 0,count=0;
	int count2 = 0;
	int temp = 0;
	while(temp<2)
	{
		temp++;
		count=0;
		count2 = count1;
		int d[500][500];
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				d[i][j] = -1;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(d[i][j]==-1 && a[i][j]=='.')
				{
					d[i][j]=0;
					int u = i*m + j;
					q.push(u);
					while(!q.empty())
					{
						int x = q.front();
						q.pop();
						count++;
						count1++;
						int i1[5];
						int j1[5];
						i1[0] = x/m;
						j1[0] = x%m;
						i1[1] = i1[0];j1[1] = j1[0] - 1;
						i1[2] = i1[0];j1[2] = j1[0] + 1;
						i1[3] = i1[0] - 1;j1[3] = j1[0];
						i1[4] = i1[0] + 1;j1[4] = j1[0];
						int k;
						bool done = true;
						for(k=1;k<=4;k++)
						{
							if((i1[k]>=0)&&(i1[k]<n)&&(j1[k]>=0)&&(j1[k]<m))
							{
								if(d[i1[k]][j1[k]]==-1 && a[i1[k]][j1[k]]=='.')
								{
									done = false;
									d[i1[k]][j1[k]]=d[i1[0]][j1[0]]+1;
									int xx = i1[k]*m + j1[k];
									q.push(xx);
								}
							}
						}
						if(count>(count2-kk) && temp==2)
						{
							a[i1[0]][j1[0]]='X';
						}
					}
					j = m;i = n;
				}

			}
		} 
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
				cout<<a[i][j];
		}
		cout<<'\n';
	}
	return 0;
}