#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#define lli long long int
#define pb push_back
using namespace std;
vector<int> parent;
vector<int> size;
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
int main()
{

	vector<vector<int> > x;
	vector<vector<int> > y;
	x.resize(100001);
	y.resize(100001);
	parent.resize(100001);
	size.resize(100001);
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		int cur_x;
		int cur_y;
		cin>>cur_x;
		cin>>cur_y;
		x[cur_x].push_back(cur_y);
		y[cur_y].push_back(cur_x);
	}
	for(i=1;i<=100000;i++)
	{
		// if(x[i].size()>1)
		// 	sort(x[i].begin(),x[i].end());
		// if(y[i].size()>1)
		// 	sort(y[i].begin(),y[i].end());
		parent[i] = i;
		size[i] = 1;
	}
	for(i=1;i<100001;i++)
	{
		if(y[i].size()>1)
		{
			int j;
			for(j=1;j<y[i].size();j++)
			{
				union_sets(y[i][j],y[i][j-1]);
			}
		}
	}

	vector<int> group;
	group.resize(100001);
	for(i=1;i<100001;i++)
		group[i] = find_set(i);
	vector<vector<int> > classes;
	classes.resize(100001);
	for(i=1;i<100001;i++)
		classes[group[i]].pb(i);
	vector<set<int> > class_size;
	class_size.resize(100001);
	for(i=1;i<100001;i++)
	{
		int j;
		for(j=0;j<classes[i].size();j++)
		{
			int k;
			for(k=0;k<x[classes[i][j]].size();k++)
				class_size[i].insert(x[classes[i][j]][k]);
		}
	}
	lli ans = 0;
	for(i=1;i<100001;i++)
	{
		int x_cnt = classes[i].size();
		int y_cnt = class_size[i].size();
		ans = ans + x_cnt*y_cnt;
	}
	ans = ans - n;
	cout<<ans<<endl;
	return 0;
}
