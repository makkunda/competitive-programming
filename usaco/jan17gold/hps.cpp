
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
long int mx(long int a,long int b)
  {
    if(a>b)
        return a;
    return b;  
  }
int main() {
    ofstream fout ("hps.out");
    ifstream fin ("hps.in");
    long int n,i,k;
    fin>>n>>k;
    vector<char> c(n);
    vector<long int> h(n+1);
    vector<long int> p(n+1);
    vector<long int> s(n+1);
    h[0]=p[0]=s[0]=0;
    for(i=0;i<n;i++)
         fin>>c[i];
    for(i=0;i<n;i++)
      {
        h[i+1]=h[i];p[i+1]=p[i];s[i+1]=s[i];
        if(c[i]=='H')
              h[i+1]++;
        else if(c[i]=='P')
              p[i+1]++;
        else
              s[i+1]++;          
      }   
    long int ans = 0;
    if(k==0)
        ans = mx(mx(h[n],p[n]),s[n]);
    else if(k==1)
      {
        ans = mx(mx(h[n],p[n]),s[n]);
        for(i=2;i<=n;i++)
           {
             if(c[i-1]!=c[i-2])
                 {
                  long int tmp;
                  if(c[i-1]=='H'&&c[i-2]=='P')
                        tmp = p[i-1]+h[n]-h[i-1];
                  else if(c[i-1]=='H'&&c[i-2]=='S')
                        tmp = s[i-1]+h[n]-h[i-1];
                  else if(c[i-1]=='S'&&c[i-2]=='P')
                        tmp = p[i-1]+s[n]-s[i-1];
                  else if(c[i-1]=='S'&&c[i-2]=='H')
                        tmp = h[i-1]+s[n]-s[i-1];
                  else if(c[i-1]=='P'&&c[i-2]=='H')
                        tmp = h[i-1]+p[n]-p[i-1];
                  else if(c[i-1]=='P'&&c[i-2]=='S')
                        tmp = s[i-1]+p[n]-p[i-1];
                  ans = mx(ans,tmp);                                  
                 }
           }
      }
    else
       ans = mx(mx(h[n],p[n]),s[n]);
    fout<<ans<<"\n";             
    return 0;
}