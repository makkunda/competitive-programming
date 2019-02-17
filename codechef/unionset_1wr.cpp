#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,k,i;
	     cin>>n>>k;
	     int num;
	     if(k%64==0)
	      {
	          num = k/64;
	      }
	     else
	      {
	          num = k/64;
	          num = num+1;
	      }
	     vector<vector<ll> > a;
	     vector<int> leng;
	     a.resize(n);leng.resize(n);
	     for(i=0;i<n;i++)
	      a[i].resize(num);
	     for(i=0;i<n;i++)
	      {
	          int j;
	          cin>>leng[i];
	          for(j=0;j<leng[i];j++)
	           {
	               int x;
	               cin>>x;
	               x--;
	               int x_num = x/64;
	               int x_mod = x%64;
	               ll add = 1<<x_mod;
	               a[i][x_num] = a[i][x_num] + add;
	           }
	      }
	     vector<ll> cmpr;
	     cmpr.resize(num);
	     for(i=1;i<=k;i++)
	      {
	               int x;
	               x=i;
	               x--;
	               int x_num = x/64;
	               int x_mod = x%64;
	               ll add = 1<<x_mod;
	               cmpr[x_num] = cmpr[x_num] + add;
	      }
	     ll ans = 0;
	     int j,jj;
	     for(i=0;i<n;i++)
	        {
	            if(leng[i]==k)
	               ans = ans + (n-1-i);
	            else {    
	            for(j=(i+1);j<n;j++)
	             {
	                 if((leng[i]+leng[j])>=k){
	                 vector<ll> orr;
	                 orr.resize(num);
	                 for(jj=0;jj<num;jj++)
	                  {
	                      orr[jj] = a[i][jj]|a[j][jj];
	                  }
	                  bool done = true;
	                  for(jj=0;jj<num;jj++)
	                  {
	                      if(orr[jj]!=cmpr[jj])
	                         {
	                             done = false;
	                             break;
	                         }
	                  }
	                  if(done)
	                     ans++; }
	             } }
	             
	        }
	     cout<<ans<<"\n";     
	 }
	return 0;
}
