
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> prime;
void gp()
{
    prime.resize(10);
    prime[0]=2;prime[1]=3;prime[2]=5;prime[3]=7;prime[4]=11;prime[5]=13;prime[6]=17;prime[7]=19;
    prime[8]=23;prime[9]=29;
    for(int j = 31;j<998;j=j+2)
    {
        bool p = true;
        for(int k = 0;k<prime.size();k++)
        {
            if(j%prime[k]==0)
              {
                  p = false;
                  break;
              }
        }
        if(p)
           prime.push_back(j);
    }
}
long int lp(long int a)
{
     int sq = (int)sqrt(a) + 1;
     int ind =(int) (upper_bound(prime.begin(),prime.end(),sq) - prime.begin());
     for(int i = 0;i<ind;i++)
       {
           if(a%prime[i] == 0)
                return (long int)prime[i];
       }
    return a;   
}
long int mx(long int a,long int b)
{
   if(a>b)
      return a;
   return b;   
}
int main() {
    gp();
    int t;
    cin>>t;
    while(t--)
    {
        long int n,m,i,l,r;
        int typ;
        long int a[100000];
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<m;i++)
        {
            cin>>typ>>l>>r;
            if(typ)
            {
                long int result = 1;
                for(long int x = l-1;x<r;x++)
                {
                    result = mx(result,lp(a[x]));
                }
                cout<<result<<" ";
            }
            else
            {
                for(long int x = l-1;x<r;x++)
                {
                    a[x] = a[x] / lp(a[x]) ;
                }
            }
        }
     cout<<endl;   
    }
    return 0;
}