#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long int
#define MOD 1000000007
using namespace std;
ll mx(ll a,ll b)
 {
  if(a>b)
    return a;
  return b;
 }
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
     {
        int i;
        vector<ll> a,arev;
        vector<ll> csum;
        cin>>n;
        a.resize(n);arev.resize(n);csum.resize(n);
        for(i=0;i<n;i++)
             cin>>a[i];
        sort(a.begin(),a.end());
        csum[0]=a[n-1];
        for(i=0;i<n;i++)
          arev[i]=a[n-i-1];
        for(i=1;i<n;i++)
          csum[i]=csum[i-1]+arev[i];
        int pcount = 0;
        ll psum = 0;
        ll ans = csum[n-1];
        for(i=0;i<n;i++)
        {
          pcount++;
          psum=psum+arev[i];
          ll tmp = psum*pcount + csum[n-1] - csum[i];
          ans = mx(ans,tmp);
        }
        cout<<ans<<"\n";
     }
    return 0;
}