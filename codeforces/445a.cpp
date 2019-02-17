#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n,m,i,j;
	char a[100][100];
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cin>>a[i][j];
	}
	queue<int> q;

	int d[100][100];
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
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
					int i1[5];
					int j1[5];
					i1[0] = x/m;
					j1[0] = x%m;
					i1[1] = i1[0];j1[1] = j1[0] - 1;
					i1[2] = i1[0];j1[2] = j1[0] + 1;
					i1[3] = i1[0] - 1;j1[3] = j1[0];
					i1[4] = i1[0] + 1;j1[4] = j1[0];
					int k;
					for(k=1;k<=4;k++)
					{
						if((i1[k]>=0)&&(i1[k]<n)&&(j1[k]>=0)&&(j1[k]<m))
						{
							if(d[i1[k]][j1[k]]==-1 && a[i1[k]][j1[k]]=='.')
							{
								d[i1[k]][j1[k]]=d[i1[0]][j1[0]]+1;
								int xx = i1[k]*m + j1[k];
								q.push(xx);
							}
						}
					}
				}
			}

		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='.')
			{
				if(d[i][j]%2)
					cout<<'B';
				else
					cout<<'W';
			}
			else
				cout<<a[i][j];
		}
		cout<<'\n';
	}
	return 0;
}