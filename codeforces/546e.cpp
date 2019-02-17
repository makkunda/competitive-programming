#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define INF 1000000000

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main()
{
	int n1,m;
	vector<int> a;
	vector<int> b;
	cin>>n1>>m;
	int i,j;
	a.resize(n1);
	b.resize(n1);
	for(i=0;i<n1;i++)
	{
		cin>>a[i];
	}
	int tot_sum = 0;
	for(i=0;i<n1;i++)
	{
		cin>>b[i];
		tot_sum = tot_sum + b[i];
	}
	int p,q;
	n= 2*n1 + 2;
	adj.resize(n);
	capacity.resize(n);
	for(i=0;i<n;i++)
		capacity[i].resize(n);
	for(i=0;i<m;i++)
	{
		cin>>p>>q;
		adj[p].push_back(n1+q);
		adj[q].push_back(n1+p);
		capacity[p][n1+q] = 200;
		capacity[q][n1+p] = 200;
	}
	for(i=0;i<n1;i++)
	{
		adj[0].push_back(i+1);
		adj[n1+i+1].push_back(n-1);
		capacity[0][i+1] = a[i];
		capacity[n1+i+1][n-1] = b[i];
	}
	int tot_flow = maxflow(0,n-1);
	if(tot_flow<tot_sum)
		cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		for(i=1;i<=n1;i++)
		{
			for(j=1;j<=n1;j++)
			{
				// cout<<max(0,200 - capacity[i][j])<<" ";
				if(capacity[i][n1+j]==0)
					cout<<"0 ";
				else if(capacity[i][n1+j]>=200)
					cout<<"0 ";
				else 
				{
					int ans = 200 - capacity[i][n1+j];
					if(ans>100)
						ans = 0;
					cout<<ans<<" ";
				}
			}
			cout<<"\n";
		}

	}
	return 0;
}