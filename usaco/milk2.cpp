/*
ID: makkund2
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct interval{
	long int start;
	long int end;
	interval* next;
};
long int mx(long int a,long int b)
 {
 	if(a>b)
 		return a;
 	return b;
 }
int main(){
ofstream fout("milk2.out");
ifstream fin("milk2.in");
long int x,y;
long int m[5000][2];
int n,i,counter=1;
fin>>n;
fin>>x>>y;
interval* head = new interval;
//fout<<"interval created initially"<<endl;
head->start = x;
head->end = y;
head->next = NULL;
for(i=1;i<n;i++)
 {
 fin>>x>>y;
 bool add = false;
 interval* temp = head;
 interval* tempprev = NULL;
  while(temp!=NULL && !add)
 {
 	if(y<temp->start)
 	{
 		interval* xy = new interval;
 		//fout<<"interval created before"<<endl;
 		xy->start = x;
 		xy->end = y;
 		xy->next = temp;
 		if(tempprev!=NULL)
 			 tempprev->next = xy;
 		else
 		     head = xy;	
 		add = true;	
 	}
 	else if(x<temp->start && y<=temp->end)
 	{
 		temp->start = x;
 		add = true;
 	}
 	else if(x>=temp->start && y<=temp->end)
 		   add = true;
 	else if(y>temp->end && x<=temp->end)
 	 {
 	 	if(x<temp->start)
 	 		 temp->start = x;
 	 	interval* temp2 = temp->next;
 	 	while(temp2!=NULL && !add)
 	 	{
 	 		if(y<temp2->start)
 	 		{
 	 			temp->end = y;
 	 			temp->next = temp2;
 	 			add = true;
 	 		}
 	 		else if(y<=temp2->end)
 	 		{
 	 			temp->end = temp2->end;
 	 			temp->next = temp2->next;
 	 			add = true;
 	 		}
 	 		else
 	 			temp2 = temp2->next;
 	 	}
 	 	if(!add)
 	 	{
 	 		temp->end = y;
 	 		temp->next = NULL;
 	 		add = true;
 	 	}

 	 }	
 	 else
 	 {
 	 	tempprev = temp;
 	 	temp = temp->next;
 	 }
 }
 if(!add)
  {
 	interval* xy = new interval;
 	//fout<<"interval created after"<<endl;
 		xy->start = x;
 		xy->end = y;
 		xy->next = NULL;
 		tempprev->next = xy;
  }
 }
long int prevtime = head->start,currempty;
long int maxempty = 0;
long int maxfull = 0,currfull; 
interval* temp1 = head;
int coun = 0;
while(temp1!=NULL)
{
	currfull = temp1->end - temp1->start;
	currempty = temp1->start - prevtime;
	prevtime = temp1->end;
	maxempty = mx(maxempty,currempty);
	maxfull = mx(currfull,maxfull);
	temp1 = temp1->next;
//	fout<<"I am in "<<coun++<<" "<<currfull<<endl;
	
}
fout<<maxfull<<" "<<maxempty<<"\n";
return 0;
}