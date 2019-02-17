/*
ans - 1074                
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int mx(int a,int b)
  {
      if(a>b)
        return a;
      return b;
  }
int main() {
    int x[15][15];
    int ans[15][15];
    int i,j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<=i;j++)
          cin>>x[i][j];
    }
    ans[0][0] = x[0][0];
    for(i=1;i<15;i++)
        ans[i][i] = ans[i-1][i-1] + x[i][i];
    for(i=1;i<15;i++)
        ans[i][0] = ans[i-1][0]+x[i][0];
    for(i=1;i<15;i++)
    {
        for(j=1;j<i;j++)
            ans[i][j] = x[i][j] + mx(ans[i-1][j-1],ans[i-1][j]);
    }
    int fans = 0;
    for(i=0;i<15;i++)
         fans = mx(fans,ans[14][i]);
    cout<<fans;
}