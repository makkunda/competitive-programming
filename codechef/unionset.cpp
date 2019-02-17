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
       vector<vector<ll> > a;
       vector<int> leng;
       a.resize(n);leng.resize(n);
       for(i=0;i<n;i++)
        {
            int j;
            cin>>leng[i];
            a[i].resize(leng[i]);
            for(j=0;j<leng[i];j++)
             {
                 cin>>a[i][j];
             }
           // sort(a[i].begin(),a[i].end());    
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
                    vector<int> tot;
                    tot.resize(k);
                    for(jj=0;jj<leng[i];jj++)
                          tot[a[i][jj]-1]=1;
                    for(jj=0;jj<leng[j];jj++)
                          tot[a[j][jj]-1]=1;
                    bool done = true;
                    for(jj=0;jj<k;jj++)
                     {
                         if(tot[jj]==0)
                          {
                              done=false;
                              break;
                          }
                     }
                    if(done)
                       ans++;    }
                   
               }
               } 
              
          }
               
       cout<<ans<<"\n";     
   }
  return 0;
}
