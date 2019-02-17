
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
ll ab(ll a)
 {
     if(a>0)
       return a;
     return -1*a;
 }
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll n,l,a,b,i;
        cin>>n>>l>>a>>b;
        vector<ll> s;
        s.resize(n);
        for(i=0;i<n;i++)
        cin>>s[i];
        sort(s.begin(),s.end());
        for(i=0;i<n;i++)
          s[i]=s[i]-a-i*l;
        sort(s.begin(),s.end());
        ll x1,x2,x11,x22;
        ll a1=0,a2=0;
        if(n%2)
         {
             x1 = (n-1)/2;
            x11 = mx(s[x1],0);x11 = mn(x11,b-a-(n)*l);
             for(i=0;i<n;i++)
               a1 = a1 + ab(x11 - s[i]);
             cout<<a1<<"\n";
         }
        else
         {
             x1 = n/2;
             x2 = x1-1;
             x11 = mx(s[x1],0);x22 = mx(s[x2],0);
             x11 = mn(x11,b-a-(n)*l);x22 = mn(x22,b-a-(n)*l);
             for(i=0;i<n;i++)
               {
                   a1 = a1 + ab(x11 - s[i]);
                   a2 = a2 + ab(x22 - s[i]);
               }
              cout<<mn(a1,a2)<<"\n";  
         }
    }
    
    return 0;
}