#include <iostream>
using namespace std;
void solve2(int x0,int y0)
 {
 	cout<<x0<<" "<<y0<<" "<<x0<<" "<<y0+1<<"\n";
 	cout<<x0+1<<" "<<y0<<" "<<x0+1<<" "<<y0+1<<"\n";
 	cout<<x0<<" "<<y0<<" "<<x0+1<<" "<<y0<<"\n";
 	cout<<x0<<" "<<y0+1<<" "<<x0+1<<" "<<y0+1<<"\n";
 }
void solve4(int x0,int y0)
 {
 	    solve2(x0,y0);
		solve2(x0+2,y0);
		solve2(x0,y0+2);
		solve2(x0+2,y0+2);
		solve2(x0+1,y0+1);
		solve2(x0,y0);
		solve2(x0+2,y0);
		solve2(x0,y0+2);
		solve2(x0+2,y0+2);
 }
void solve8(int x0,int y0)
 {
 	    solve4(x0,y0);
		solve4(x0+4,y0);
		solve4(x0,y0+4);
		solve4(x0+4,y0+4);
		solve2(x0+3,y0+3);
		solve4(x0,y0);
		solve4(x0+4,y0);
		solve4(x0,y0+4);
		solve4(x0+4,y0+4);
 }
void solve16(int x0,int y0)
 {
 		solve8(x0,y0);
		solve8(x0+8,y0);
		solve8(x0,y0+8);
		solve8(x0+8,y0+8);
		solve2(x0+7,y0+7);
		solve8(x0,y0);
		solve8(x0+8,y0);
		solve8(x0,y0+8);
		solve8(x0+8,y0+8);
 } 
void row5(int x0,int y0)
{
	cout<<x0<<" "<<y0<<" "<<x0<<" "<<y0+1<<"\n";
	cout<<x0<<" "<<y0+2<<" "<<x0<<" "<<y0+3<<"\n";
	cout<<x0<<" "<<y0+2<<" "<<x0<<" "<<y0+1<<"\n";
	cout<<x0<<" "<<y0+2<<" "<<x0<<" "<<y0+3<<"\n";
	cout<<x0<<" "<<y0+2<<" "<<x0<<" "<<y0+1<<"\n";
	cout<<x0<<" "<<y0<<" "<<x0<<" "<<y0+1<<"\n";
	cout<<x0<<" "<<y0+2<<" "<<x0<<" "<<y0+3<<"\n";
	cout<<x0<<" "<<y0+3<<" "<<x0<<" "<<y0+4<<"\n";
	cout<<x0<<" "<<y0+2<<" "<<x0<<" "<<y0+3<<"\n";
	cout<<x0<<" "<<y0+2<<" "<<x0<<" "<<y0+3<<"\n";
	cout<<x0<<" "<<y0+2<<" "<<x0<<" "<<y0+1<<"\n";
	cout<<x0<<" "<<y0+2<<" "<<x0<<" "<<y0+3<<"\n";
	cout<<x0<<" "<<y0+2<<" "<<x0<<" "<<y0+1<<"\n";
	cout<<x0<<" "<<y0<<" "<<x0<<" "<<y0+1<<"\n";
	cout<<x0<<" "<<y0+2<<" "<<x0<<" "<<y0+3<<"\n";
}
void col5(int x0,int y0)
{
	cout<<x0<<" "<<y0<<" "<<x0+1<<" "<<y0<<"\n";
	cout<<x0+2<<" "<<y0<<" "<<x0+3<<" "<<y0<<"\n";
	cout<<x0+2<<" "<<y0<<" "<<x0+1<<" "<<y0<<"\n";
	cout<<x0+2<<" "<<y0<<" "<<x0+3<<" "<<y0<<"\n";
	cout<<x0+2<<" "<<y0<<" "<<x0+1<<" "<<y0<<"\n";
	cout<<x0<<" "<<y0<<" "<<x0+1<<" "<<y0<<"\n";
	cout<<x0+2<<" "<<y0<<" "<<x0+3<<" "<<y0<<"\n";
	cout<<x0+3<<" "<<y0<<" "<<x0+4<<" "<<y0<<"\n";
	cout<<x0+2<<" "<<y0<<" "<<x0+3<<" "<<y0<<"\n";
	cout<<x0+2<<" "<<y0<<" "<<x0+3<<" "<<y0<<"\n";
	cout<<x0+2<<" "<<y0<<" "<<x0+1<<" "<<y0<<"\n";
	cout<<x0+2<<" "<<y0<<" "<<x0+3<<" "<<y0<<"\n";
	cout<<x0+2<<" "<<y0<<" "<<x0+1<<" "<<y0<<"\n";
	cout<<x0<<" "<<y0<<" "<<x0+1<<" "<<y0<<"\n";
	cout<<x0+2<<" "<<y0<<" "<<x0+3<<" "<<y0<<"\n";
}
void solve5(int x0,int y0)
{
	row5(x0,y0);
	row5(x0+1,y0);
	row5(x0+2,y0);
	row5(x0+3,y0);
	row5(x0+4,y0);
	col5(x0,y0);
	col5(x0,y0+1);
	col5(x0,y0+2);
	col5(x0,y0+3);
	col5(x0,y0+4);

}
void solve10(int x0,int y0)
 {
 	    solve5(x0,y0);
		solve5(x0+5,y0);
		solve5(x0,y0+5);
		solve5(x0+5,y0+5);
		solve2(x0+4,y0+4);
		solve5(x0,y0);
		solve5(x0+5,y0);
		solve5(x0,y0+5);
		solve5(x0+5,y0+5);
 }
void solve20(int x0,int y0)
 {
 	    solve10(x0,y0);
		solve10(x0+10,y0);
		solve10(x0,y0+10);
		solve10(x0+10,y0+10);
		solve2(x0+9,y0+9);
		solve10(x0,y0);
		solve10(x0+10,y0);
		solve10(x0,y0+10);
		solve10(x0+10,y0+10);
 } 
/*void solve11(int x0,int y0)
 {
 	 solve10(x0,y0);
 	 solve10(x0+1,y0);
 	 solve10(x0,y0+1);
 	 solve10(x0+1,y0+1);
 }*/ 
int main()
{
	int n;
	cin>>n;
	if(n==2){
	cout<<4<<"\n";
	solve2(1,1);}
	else if(n==4)
	{
		cout<<36<<"\n";
		solve4(1,1);
		
	}
	else if(n==8)
	{
		cout<<292<<"\n";
		solve8(1,1);
	}
	else if(n==16)
	{
		cout<<2340<<"\n";
		solve16(1,1);
	}
	else if(n==5)
	{
		cout<<150<<"\n";
		solve5(1,1);
	}
	else if(n==20)
	{
		cout<<9636<<"\n";
		solve20(1,1);
	}
	else
		cout<<0<<"\n";
	return 0;
}