#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
    a.resize(n);
    for(i=0;i<n;i++)
    {
      cin>>x;
      if(x=='1')
        a[i]=1;
      else
        a[i]=0;
    }
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
    for(i=0;i<n;i++)
    {
      if(i%2)
       {
         if(a[i]==0)
           cnt1++;
         else
           cnt++;
       }
      else
        {
          if(a[i]==1)
           cnt1++;
          else
            cnt++;
        }
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
            /* long long int tmp = 1;
             while(curcnt>mid)
              {
                an1 = an1 + tmp;
                if(curcnt%2)
                  curcnt = (curcnt-1)/2;
                else
                  curcnt = curcnt/2;
                tmp = tmp*2;
              }  */
           }
           queue<long long int> q;
           q.push(curcnt);
           while(q.front()>mid)
            {
              an1++;
              long long int x = q.front();
              q.pop();
              x = x-1;
              long long int y,z;
              y=x/2;
              z = (x+1)/2;
              q.push(z);
              q.push(y);
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
