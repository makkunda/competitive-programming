#include <iostream>
#include <vector>
#include <queue>
#define lli long long int
#define mod 1000000007
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j;
		char a[52][52];
		cin>>n;
		vector<vector<int> > adj;
		adj.resize(2500);
		for(i=0;i<=(n+1);i++)
			a[i][0]=a[0][i]=a[n+1][i]=a[i][n+1]='.';
		char x[2500];
		for(i=0;i<2500;i++)
			x[i]='#';

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				{
					cin>>a[i][j];
					x[n*(i-1)+(j-1)]=a[i][j];
				}	
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				int cur = n*(i-1) + (j-1);
				int curi = n*(i) + (j-1);
				int curj = n*(i-1) + j;
				if(curi<=2499){
				if(a[i][j]!='.'&&a[i+1][j]!='.'/*&&x[curi]!='#'*/)
				{
				//	cout<<"edge "<<cur<<" "<<x[cur]<<" - "<<curi<<" "<<x[curi]<<endl;
					adj[cur].push_back(curi);
					adj[curi].push_back(cur);
				}}
				if(curj<=2499){
				if(a[i][j]!='.'&&a[i][j+1]!='.'/*&&x[curj]!='#'*/)
				{
				//	cout<<"edge "<<cur<<" "<<x[cur]<<" - "<<curj<<" "<<x[curj]<<endl;
					adj[cur].push_back(curj);
					adj[curj].push_back(cur);
				}}
			}
		}
		long long int ans = 1;
		vector<int> vis;
		vis.resize(2500);
		int curc = 0;
		for(i=0;i<(n*n);i++)
		{
			if(vis[i]==0 &&(x[i]!='.'))
			{
				curc++;
				vis[i] = curc;
				long int cntq,cntb,cntg,cntp,sz;
				cntq=cntb=cntg=cntp=sz=0;
				queue<int> q;
				q.push(i);
				while(!q.empty())
				{
					int z = q.front();
					q.pop();
					sz++;
					if(x[z]=='?')
						cntq++;
					else if(x[z]=='B')
						cntb++;
					else if(x[z]=='G')
						cntg++;
					else if(x[z]=='P')
						cntp++;
					for(int j = 0;j<adj[z].size();j++)
					{
						if(vis[adj[z][j]]==0)
						{
							vis[adj[z][j]]=curc;
							q.push(adj[z][j]);
						}
					}
				}
				int tmpans ;
				if(sz==1 && cntq==1)
					tmpans = 3;
				else if(sz==1)
					tmpans = 1;
				else if(sz==cntq)
					tmpans = 2;
				else if(cntg>0)
					tmpans = 0;
				else if((cntb*cntp + cntp*cntg +cntb*cntg)==0)
					tmpans = 1;
				else 
					tmpans = 0;
				ans = ans*tmpans;
				ans = ans%mod;
				ans = (ans+mod)%mod;
			//	cout<<curc<<" "<<sz<<" "<<tmpans<<endl;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}