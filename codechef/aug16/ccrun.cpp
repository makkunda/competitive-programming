#include <iostream>
#include <vector>
using namespace std;
long long int mn(long long int x,long long int y)
 {
    if(x<y)
        return x;
    else
        return y;
 }
int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        long long int n,i;
        cin>>n;
        long long int r[600000],ss=0;
        for(i=0;i<n;i++)
        {
            cin>>r[i];
            ss=ss+r[i];
            r[n+i]=r[i];
            r[2*n+i]=r[i];
        }
        long long int start,end,start1,end1;
        cin>>start>>end;
        start = start - 1;
        end = end - 1;
        long long int min1 =1e+13,cur=0,cur1=0,min2=1e+13;
        long long int negste,sumste=0,negets,sumets=0,sum1,sum2;
        vector<long long int>pneg1;
        vector<long long int>pneg2;
        vector<long long int>sneg1;
        vector<long long int>sneg2;
        long long int s1 = end - start;
        long long int s2 = n - s1;
        pneg1.resize(s1);
        pneg2.resize(s2);
        sneg1.resize(s1);
        sneg2.resize(s2);
        for(i=n+start-1;i>=end;i--)
        {
            cur = cur + r[i];
            min1=mn(cur,min1);
            sneg2[i-end]=mn(0,2*min1);
        }
        for(i=end;i<(n+start);i++)
        {
            cur1 = cur1 + r[i];
            min2=mn(cur1,min2);
            pneg2[i-end]=mn(0,2*min2);
        }
        min1=1e+13;min2=1e+13;
        cur=0;cur1=0;
        for(i=start;i<end;i++)
        {
            cur = cur + r[i];
            min1=mn(cur,min1);
            pneg1[i-start]=mn(0,2*min1);
        }
        for(i=(end-1);i>=start;i--)
        {
            cur1 = cur1 + r[i];
            min2=mn(cur1,min2);
            sneg1[i-start]=mn(0,2*min2);
        }
        negste=0;negets=0;
        for(i=0;i<(s1-1);i++)
        {
            negets=mn(negets,pneg1[i]+sneg1[i+1]);
        }
        for(i=0;i<(s2-1);i++)
        {
            negste=mn(negste,pneg2[i]+sneg2[i+1]);
        }
        if(s1==1)
            negets=mn(0,2*r[start]);
        if(s2==1)
            negste=mn(0,2*r[end]);
        for(i=start;i<end;i++)
        {
            sumste=sumste+r[i];
        }
        sumets=ss-sumste;
        sum1=sumste+negste;
        sum2=sumets+negets;
        cout<<mn(sum1,sum2)<<endl;

    }
    return 0;
}