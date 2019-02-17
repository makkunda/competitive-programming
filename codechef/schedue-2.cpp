#include <iostream>
#include <vector>
#include <string>
using namespace std;
long long int mn(long long int a,long long int b)
 {
   if(a<b)
    return a;
  return b;
 }
long long int mx(long long int a,long long int b)
  {
    if(a>b)
     return a;
   return b;
  }
int main()
{
  ios::sync_with_stdio(false);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    long int n,k,i;
    cin>>n>>k;
    char x;
    vector<int> a;
    a.resize(n+1);
    for(i=0;i<n;i++)
    {
      cin>>x;
      if(x=='1')
        a[i]=1;
      else
        a[i]=0;
    }
    a[n] = -1;
    long long mx1 = 1;
    int prev = a[0];
    for(i=0;i<n;)
     {
       long long int curcnt = 1;
       int prev = a[i];
       i++;
       while(i<n && a[i]==prev)
        {
          curcnt++;
          i++;
        }
       mx1 = mx(mx1,curcnt);
     }
    //check for 1
    long int cnt=0,cnt1=0;
    vector<int> bb,cc;
    bb.resize(n);cc.resize(n);
    int dd =1;
    for(i=0;i<n;i++)
     {
       bb[i] = dd;
       cc[i] = 1-dd;
       dd = 1-dd;
     }
    for(i=0;i<n;i++)
    {
      if(a[i]!=bb[i])
        cnt++;
      if(a[i]!=cc[i])
        cnt1++;
    }
    if(mn(cnt,cnt1)<=k)
       cout<<1<<"\n";
    else
      {
        long long int lo,hi,mid;
        lo = 2;
        hi = mx1;
        while(lo<=hi)
        {
          mid = lo + (hi-lo)/2;
          long long int an1 = 0;
          int prev = a[0];
          long int curcnt = 1;
          for(i=0;i<n;)
           {
            // 110001111
            i++;
             while(i<n && a[i]==prev)
              {
                curcnt++;
                if(curcnt>mid)
                 {
                   an1++;
                   prev = 1-prev;
                   curcnt = 1;
                   break;
                 }
                 i++;
              }
            //  cout<<i<<"\n";
           }
          if(an1>k)
             lo = mid+1;
          else
            hi = mid - 1;
        }
        cout<<mid<<"\n";
      }
  }
  return 0;
}
