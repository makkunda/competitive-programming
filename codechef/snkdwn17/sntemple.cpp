
#include <iostream>
#include <fstream>
#include <vector>
#define ll long long int
ll mx(ll a,ll b)
 {
     if(a>b)
       return a;
     return b;
 }
ll mn(ll a,ll b)
 {
     if(a<b)
       return a;
     return b;
 } 
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,i,start;
        cin>>n;
        vector<long long int> h;
        vector<long long int> presum,frmax,bkmax;
        h.resize(n+2);
        presum.resize(n+2);frmax.resize(n+2);bkmax.resize(n+2);
        for(i=1;i<=n;i++)
         {
             cin>>h[i];
             presum[i]=presum[i-1] + h[i];
         }
        presum[n+1]=presum[n]; 
        for(i=1;i<=n;i++)
         {
            frmax[i]=mn(frmax[i-1]+1,h[i]);
         }
        bkmax[n]=1;
        for(i=n-1;i>=1;i--)
         {
             bkmax[i]=mn(bkmax[i+1]+1,h[i]);
         }
        ll ans = presum[n]+1;
        for(i=1;i<=n;i++)
         {
             ll cost = 0;
             ll len = mn(frmax[i],bkmax[i]);
             ll start = i - len + 1;
             ll end = i+len - 1;
             cost = presum[n] - len*len ;
             ans = mn(ans,cost);
         }
         cout<<ans<<"\n";
    }
    
    return 0;
}