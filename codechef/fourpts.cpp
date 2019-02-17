#include <iostream>
#include <bits/stdc++.h>
#define lli long long int
#define MOD 1000000007

double xret,yret;
using namespace std;
lli mn(lli a,lli b)
{
    if(a>b)
       return b;
    return a;   
}
lli mx(lli a,lli b)
{
    if(a<b)
       return b;
    return a;   
}

long long int modpow(long long int  a, long long int b)
{
	long long int r = 1;
	while(b>0)
	{
		if((b%2)==1) 
		   r = (r*a)%MOD;
		a = (a*a)%MOD;
		b=b/2;
	}
	return r%MOD;
}
bool iscol(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3)
 {
     int x1,y1,x2,y2,x3,y3;
     x1 = p1.first;
     x2 = p2.first;
     x3 = p3.first;
     y1 = p1.second;
     y2 = p2.second;
     y3 = p3.second;
     if(y2==y1 && y3==y2)
      {
          cout<<"YES ";
          if((x2-x1)*(x2-x3)<0)
           {
               cout<<x1<<" "<<y1<<" "<<x3<<" "<<y3<<" ";
           }
          else if((x3-x1)*(x3-x2)<0)
           {
               cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" ";
           } 
          else
           {
               cout<<x3<<" "<<y3<<" "<<x2<<" "<<y2<<" ";
           }
          return true;
      }
     else if (x1 ==x2 && x2 == x3)
      {
          cout<<"YES ";
          if((y2-y1)*(y2-y3)<0)
           {
               cout<<x1<<" "<<y1<<" "<<x3<<" "<<y3<<" ";
           }
          else if((y3-x1)*(y3-x2)<0)
           {
               cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" ";
           } 
          else
           {
               cout<<x3<<" "<<y3<<" "<<x2<<" "<<y2<<" ";
           }
          return true;
      }
     else if((y2-y1)*(x3-x2)==(y3-y2)*(x2-x1))
      {
          cout<<"YES ";
          if((x2-x1)*(x2-x3)<0)
           {
               cout<<x1<<" "<<y1<<" "<<x3<<" "<<y3<<" ";
           }
          else if((x3-x1)*(x3-x2)<0)
           {
               cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" ";
           } 
          else
           {
               cout<<x3<<" "<<y3<<" "<<x2<<" "<<y2<<" ";
           }
          return true;
      }
     else
        return false;
     
 }
bool isp (pair<int,int> p1,pair<int,int> p2,pair<int,int> p3,pair<int,int> p4)
 {
     int x1,y1,x2,y2,x3,y3,x4,y4;
     x1 = p1.first;
     x2 = p2.first;
     x3 = p3.first;
     x4 = p4.first;
     y1 = p1.second;
     y2 = p2.second;
     y3 = p3.second;
     y4 = p4.second;
     if(x1==x2 && x3==x4)
       return true;
     if(y1==y2 && y3==y4)
       return true;
     if((y4-y3)*(x2-x1)==(y2-y1)*(x4-x3))
       return true;
     return false;
 }
void intersect(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3,pair<int,int> p4)
 {
    int x1,y1,x2,y2,x3,y3,x4,y4;
     x1 = p1.first;
     x2 = p2.first;
     x3 = p3.first;
     x4 = p4.first;
     y1 = p1.second;
     y2 = p2.second;
     y3 = p3.second;
     y4 = p4.second;
     lli xnum,xden,ynum,yden;
     xnum = (x1*y2-y1*x2)*(x3-y4) - (x1-x2)*(x3*y4-y3*x4);
     ynum = (x1*y2-y1*x2)*(y3-y4) - (y1-y2)*(x3*y4-y3*x4);
     xden = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
     yden = xden;
     xret = (double)xnum/(double)xden;
     yret = (double)ynum/(double)yden;
     pair<double,double> pret;
     pret = make_pair(xret,yret);

 }
int ornt(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3) 
 {
    int x1,y1,x2,y2,x3,y3;
     x1 = p1.first;
     x2 = p2.first;
     x3 = p3.first;
     y1 = p1.second;
     y2 = p2.second;
     y3 = p3.second;
     int val = (y2 - y1) * (x3 - x2) -
              (x2 - x1) * (y3- y2);
     if (val == 0) return 0;
     return (val > 0)? 1: 2;
 }
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	    int x1,y1,x2,y2,x3,y3,x4,y4;
	    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	    pair<int,int> p1,p2,p3,p4;
	    p1 = make_pair(x1,y1);
	    p2 = make_pair(x2,y2);
	    p3 = make_pair(x3,y3);
	    p4 = make_pair(x4,y4);
	    if(iscol(p1,p2,p3))
	     {
	         cout<<x4<<" "<<y4<<"\n";
	     }
	    else if(iscol(p1,p2,p4))
	     {
	         cout<<x3<<" "<<y3<<"\n";
	     }
	    else if(iscol(p1,p3,p4))
	     {
	         cout<<x2<<" "<<y2<<"\n";
	     }
	    else if(iscol(p2,p3,p4))
	     {
	         cout<<x1<<" "<<y1<<"\n";
	     }
	    else
	     {
	         vector<pair<int,int> > points;
	         points.push_back(p1);
	         points.push_back(p2);
	         points.push_back(p3);
	         points.push_back(p4);
	         vector<pair<int,int> > hull;
 
    
             int l = 0;
             for (int i = 1; i < 4; i++){
                if (points[i].first < points[l].first)
                   l = i; }
            
             int p = l, q;
    do
    {
        hull.push_back(points[p]);
 
       
        q = (p+1)%4;
        for (int i = 0; i < 4; i++)
        {

           if (ornt(points[p], points[i], points[q]) == 2)
               q = i;
        }
 
        p = q;
 
    } while (p != l);
            
         
         if(hull.size()<4)
           cout<<"NO\n";
         else
          {
            cout<<"YES ";
            pair<int,int> p5,p6,p7,p8;
            p5 = hull[0];
            p6 = hull[1];
            p7 = hull[3];
            p8 = hull[2];
            if(isp(p5,p6,p7,p8))
             {
                if(isp(p5,p7,p6,p8))
                 {
                    int xx,yy ;
                    xx = 2*p6.first - p5.first;
                    yy = 2*p6.first - p5.first;
                    pair<int,int> p9;
                    p9 = make_pair(xx,yy);
                    intersect(p5,p7,p9,p8);
                    pair<double,double> p10(xret,yret);
                    
                    cout<<fixed<<setprecision(12)<<p5.first<<" "<<p5.second<<" "<<p10.first<<" "<<p10.second<<" "<<p9.first<<" "<<p9.second<<"\n";
                 }
                else
                 {
                    intersect(p5,p7,p6,p8); 
                    pair<double,double> p9(xret,yret); 
                    if(p5.first==p7.first)
                     {
                         double y5,y7,y9;
                         y5 = p5.second;
                         y7 = p7.second;
                         y9 = p9.second;
                         if((y7-y5)*(y7-y9)>(0))
                          {
                              pair<int,int> tmp;
                              tmp = p5;
                              p5 = p7;
                              p7 = tmp;
                          }
                     }
                    else
                     {
                        double y5,y7,y9,x5,x7,x9;
                         x5 = p5.first;
                         x7 = p7.first;
                         y5 = p5.second;
                         y7 = p7.second;
                         x9 = p9.first;
                         if((x7-x5)*(x7-x9)>(0))
                          {
                              pair<int,int> tmp;
                              tmp = p5;
                              p5 = p7;
                              p7 = tmp;
                          } 
                     }
                     
                     
                    if(p6.first==p8.first)
                     {
                         double y6,y8,y9;
                         y6 = p6.second;
                         y8 = p8.second;
                         y9 = p9.second;
                         if((y8-y6)*(y8-y9)>(0))
                          {
                              pair<int,int> tmp;
                              tmp = p6;
                              p6 = p8;
                              p8 = tmp;
                          }
                     }
                    else
                     {
                        double y6,y8,y9,x6,x8,x9;
                         x6 = p6.first;
                         x8 = p8.first;
                         y6 = p6.second;
                         y8 = p8.second;
                         x9 = p9.first;
                         if((x8-x6)*(x8-x9)>(0))
                          {
                              pair<int,int> tmp;
                              tmp = p6;
                              p6 = p8;
                              p8 = tmp;
                          } 
                     }
                    cout<<fixed<<setprecision(12)<<p5.first<<" "<<p5.second<<" "<<p6.first<<" "<<p6.second<<" "<<p9.first<<" "<<p9.second<<"\n";
                 }
             }
            else
             {
                intersect(p5,p6,p7,p8);
                pair<double,double> p9(xret,yret);
                if(p5.first==p6.first)
                     {
                         double y5,y6,y9;
                         y5 = p5.second;
                         y6 = p6.second;
                         y9 = p9.second;
                         if((y6-y5)*(y6-y9)>(0))
                          {
                              pair<int,int> tmp;
                              tmp = p6;
                              p6 = p5;
                              p5 = tmp;
                          }
                     }
                    else
                     {
                        double y5,y6,y9,x5,x6,x9;
                         x5 = p5.first;
                         x6 = p6.first;
                         y5 = p5.second;
                         y6 = p6.second;
                         x9 = p9.first;
                         if((x6-x5)*(x6-x9)>(0))
                          {
                              pair<int,int> tmp;
                              tmp = p6;
                              p6 = p5;
                              p5 = tmp;
                          } 
                     }
                     
                     
                    if(p7.first==p8.first)
                     {
                         double y7,y8,y9;
                         y7 = p7.second;
                         y8 = p8.second;
                         y9 = p9.second;
                         if((y8-y7)*(y8-y9)>(0))
                          {
                              pair<int,int> tmp;
                              tmp = p7;
                              p7 = p8;
                              p8 = tmp;
                          }
                     }
                    else
                     {
                        double y7,y8,y9,x7,x8,x9;
                         x7 = p7.first;
                         x8 = p8.first;
                         y7 = p7.second;
                         y8 = p8.second;
                         x9 = p9.first;
                         if((x8-x7)*(x8-x9)>(0))
                          {
                              pair<int,int> tmp;
                              tmp = p7;
                              p7 = p8;
                              p8 = tmp;
                          } 
                     }
                 
                 
                 cout<<fixed<<setprecision(12)<<p5.first<<" "<<p5.second<<" "<<p7.first<<" "<<p7.second<<" "<<p9.first<<" "<<p9.second<<"\n";
             }
          }
           
	     }
	}
	return 0;
}
