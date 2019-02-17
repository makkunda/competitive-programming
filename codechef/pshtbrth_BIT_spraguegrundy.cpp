#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<long long int> seg;
long long int n;
void update(long long int loc,long long int val)
 {
 	while(loc<=n)
 	{
 		seg[loc]=seg[loc]^val;
 		loc = loc + (loc&(-loc));
 	}
 }
long long int totalxo(long long int loc)
{
	long long int ans = 0;
	while(loc>=1)
	{
		ans = ans ^ seg[loc];
		loc = loc - (loc&(-loc));
	}
	return ans;
}
long long int rangexo(long long int start,long long int end)
{
	return (totalxo(end) ^ totalxo(start-1));
}
int mex(vector<int> st)
{
	sort(st.begin(),st.end());
	if(st[0]!=0)
		return 0;
	int i;
	for(i = 1;i<st.size();i++)
	{
		if((st[i]!=st[i-1])&&(st[i]!=(st[i-1]+1)))
			 return (st[i-1]+1);
	}
	return (st[i-1]+1);
}
int main()
{
	long long int tp[16];
	tp[0]=1;
	long long int i,j,k,l,u,v;
	for(i=1;i<16;i++)
		tp[i]=2*tp[i-1];
	vector<long long int> subm;
	for(i=0;i<4;i++)
	{
		for(j=i;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				for(l=k;l<4;l++)
				{
					long long int num = 0;
					for(u=i;u<=j;u++)
					{
						for(v=k;v<=l;v++)
						{
							int nm = 4*u + v;
							num = num + tp[nm];
						}
					}
					subm.push_back(num);
				}
			}
		}
	}
	sort(subm.begin(),subm.end());
	long long int MAX = 2*tp[15];
	vector<long long int> nim;
	nim.resize(MAX);
	nim[0]=0;
	for(i=1;i<MAX;i++)
	{
		vector<int> mexset;
		for(j=0;j<subm.size();j++)
		{
			if((i|subm[j])==i)
				mexset.push_back(nim[i-subm[j]]);
			if(subm[j]>i)
				 break;
		}
		nim[i] = mex(mexset);
	}
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		seg.resize(0);
		long long int m;
		cin>>n>>m;
		seg.resize(n+1);
		vector<int> arr;
		arr.resize(n+1);
		for(i=1;i<=n;i++)
		{
			char x;
			long long int tnum = 0;
			for(j=0;j<4;j++)
			{
				for(k=0;k<4;k++)
				{
					cin>>x;
					if(x=='1')
					{
						int mnum = 4*j + k;
						tnum = tnum + tp[mnum];
					}
				}
			}
			arr[i] = nim[tnum];
			update(i,arr[i]);
		}
		while(m--)
		{
			int type;
			long long int left,right,pos;
			cin>>type;
			if(type==1)
			{
				cin>>left>>right;
				long long int a1 = rangexo(left,right);
				if(a1==0)
					cout<<"Lotsy\n";
				else
					cout<<"Pishty\n";
			}
			else
			{
				cin>>pos;
				char x;
			long long int tnum = 0;
			for(j=0;j<4;j++)
			{
				for(k=0;k<4;k++)
				{
					cin>>x;
					if(x=='1')
					{
						int mnum = 4*j + k;
						tnum = tnum + tp[mnum];
					}
				}
			}
			update(pos,arr[pos]);
			arr[pos] = nim[tnum];
			update(pos,arr[pos]);
			}
		}
	}
	return 0;
}