#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
vector<string> nm;
int ab(int x)
{
	if(x>0)
		return x;
	return -1*x;
}
bool case_equals(string s,string t)
{
	if(s.length()!=t.length())
		return false;
	int i;
	for(i=0;i<s.size();i++)
	{
		int d = (int)s[i] - (int)t[i];
		d = ab(d);
		if(d!=0 && d!=32)
			return false;
	}
	return true;
}
int find(string s)
{
	int ret = -1;
	int i;
	for(i=0;i<nm.size();i++)
	{
		if(case_equals(s,nm[i]))
			return i;
	}
	return ret;
}
int main()
{
	int n,i,j;
	cin>>n;
	vector<string> s1;
	vector<string> s2;
	s1.resize(n);s2.resize(n);
	string s3;
	for(i=0;i<n;i++)
		cin>>s1[i]>>s3>>s2[i];
	nm.push_back("Polycarp");
	for(i=0;i<n;i++)
	{
		bool isp = true;
		if(find(s1[i])==-1)
			isp=false;
		if(!isp){
			nm.push_back(s1[i]);
		//	cout<<"adding "<<s1[i]<<endl;
		}

	}
	for(i=0;i<n;i++)
	{
		bool isp = true;
		if(find(s2[i])==-1)
			isp=false;
		if(!isp){
			nm.push_back(s2[i]);
		//	cout<<"adding "<<s2[i]<<endl;
		}
	}
	int sz = nm.size();
	vector<vector<int> > adj;
	adj.resize(sz);
	for(i=0;i<n;i++)
	{
		int u = find(s1[i]);
		int v = find(s2[i]);
		adj[v].push_back(u);
	}
	vector<int> d;
	d.resize(sz);
	d[0]=1;
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(i=0;i<adj[x].size();i++)
		{
			int v = adj[x][i];
			if(d[v]==0)
			{
				d[v]=d[x]+1;
				q.push(v);
			}
		}
	}
	int mx = 1;
	for(i=0;i<sz;i++)
		mx = max(d[i],mx);
	cout<<mx<<'\n';
	return 0;
}