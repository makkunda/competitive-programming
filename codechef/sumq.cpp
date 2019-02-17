#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long int
#define MOD 1000000007
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
     {
        ll p,q,r,i;
        vector<ll> x,xs,y,z,zs;
        cin>>p>>q>>r;
        x.resize(p+2);
        x[p]=1000000001;
        xs.resize(p+2);
        y.resize(q);
        z.resize(r+2);z[r]=1000000001;
        zs.resize(r+2);
        for(i=0;i<p;i++)
          cin>>x[i];
        for(i=0;i<q;i++)
          cin>>y[i];
        for(i=0;i<r;i++)
          cin>>z[i];
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        sort(z.begin(),z.end());
        for(i=1;i<=(p);i++)
          xs[i]=(xs[i-1]+x[i])%MOD;
        for(i=1;i<=(r);i++)
          zs[i]=(zs[i-1]+z[i])%MOD;
        
        ll ans = 0;
        std::vector<ll>::iterator up;
        for(i=0;i<q;i++)
          {
              ll xl,zl,xls,zls;
              up = upper_bound (x.begin(), x.end(),y[i]);
              xl = (ll)(up - x.begin()) - 1;
              up = upper_bound (z.begin(), z.end(),y[i]);
              zl = (ll)(up - z.begin()) - 1;
              if(xl>0 && zl>0)
               {
                   ll anst = 0;
                   anst = anst + y[i]*y[i];
                   anst = anst%MOD;
                   anst = anst*xl;
                   anst = anst%MOD;
                   anst = anst*zl;
                   anst = anst%MOD;
                   ans = (anst + ans)%MOD;
                   xls = xs[xl];zls=zs[zl];
                   anst = (xls*zls)%MOD;
                   ans = (anst + ans)%MOD;
                   anst = (xls*zl)%MOD;
                   anst = (anst*y[i])%MOD;
                   ans = (anst + ans)%MOD;
                   anst = (xl*zls)%MOD;
                   anst = (anst*y[i])%MOD;
                   ans = (anst + ans)%MOD;
               }
          }
          ans = ans%MOD;
          ans = (ans+MOD)%MOD;
          cout<<ans<<"\n";
     }
    return 0;
}