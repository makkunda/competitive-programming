#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    int k[100],f[100];
    int i,j;
    bool pos[102];
    for(i=0;i<=101;i++)
        pos[i]=true;
    cin>>n>>m;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(i=0;i<m;i++)
    {
        cin>>k[i]>>f[i];
        if(k[i]==n)
        {
            cout<<f[i]<<endl;
            return 0;
        }
        else if(k[i]>n && f[i]==1)
        {
            cout<<f[i]<<endl;
            return 0;
        }
    }
    for(i=1;i<=101;i++)
    {
        for(j=0;j<m;j++)
        {
            int lvl = k[j]/i;
            if((k[j]%i)!=0)
                lvl = lvl + 1;
            if(lvl!=f[j])
            {
                pos[i] = false;
                break;
            }
           // cout<<i<<" "<<k[j]<<" "<<lvl<<" "<<f[j]<<'\n';
        }
    }
    int cnt = 0;
    int act;
    for(i=1;i<=101;i++)
    {
        if(pos[i]){
          //  cout<<i<<endl;
            cnt++;
            act = i;
        }
        
    }
    if(cnt!=1)
        cout<<-1<<endl;
    else
    {
        int ans = n / act;
        if((n%act)!=0)
                ans = ans + 1;
        cout<<ans<<endl;
    }
    return 0;
}