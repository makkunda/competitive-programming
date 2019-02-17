#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> l,r;
    l.resize(n);
    r.resize(n);
    int i;
    for(i=0;i<n;i++)
        cin>>l[i];
    for(i=0;i<n;i++)
        cin>>r[i];
    vector<int> rank,rank_s;
    rank.resize(n);
    rank_s.resize(n+1);
    for(i=0;i<n;i++)
        {
            rank[i] = l[i] + r[i] + 1;
            rank_s[i+1] = l[i] + r[i] + 1;
        }
    sort(rank_s.begin(),rank_s.end());
    bool possible = true;
    for(i=1;i<=n;i++)
    {
        if(rank_s[i]!=rank_s[i-1] && rank_s[i]!=i)
            {
                possible = false;
                break;
            }
    }
    vector<int> c_count;
    c_count.resize(n);
    if(possible)
    {
        for(i=0;i<n;i++)
            c_count[i] = n - rank[i] + 1;
        
        for(i=0;i<n;i++)
        {
            int l_c = 0;
            int r_c = 0;
            int j;
            for(j=0;j<i;j++)
            {
                if(c_count[j]>c_count[i])
                    l_c++;
            }
            for(j=i+1;j<n;j++)
            {
                if(c_count[j]>c_count[i])
                    r_c++;
            }
            if((l_c!=l[i])||(r_c!=r[i]))
            {
                possible = false;
                break;
            }
        }
    }
    if(!possible)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        for(i=0;i<n;i++)
            cout<<c_count[i]<<" ";
        cout<<"\n";
    }
    return 0;
}