#include<bits/stdc++.h>
#include <sys/stat.h>
#include <time.h>
#include<fstream>
using namespace std;
int getArrivalTime(string s);
int getBurstTime(string s);
void print(int a[],int b[]);
//int findminArrival(int a[]);
//int findminBurstTime(int b[],int a[],int count);
int getArrivalTime(string s)
{
	struct tm* timevar;
	struct stat filedetail;
	stat(s.c_str(), &filedetail);
	timevar = gmtime(&(filedetail.st_mtime));
	int at=timevar->tm_sec;
	return at;
}
int getBurstTime(string s)
{
	int count=0;
	char c;
	fstream f;
	f.open(s.c_str());
	while(f)
	{
		f.get(c);
		count++;
	}
	f.close();
	return count;
}
void print(int a[],int b[])
{
	int i;
	for(i=0;i<6;i++)
	{
		cout<<a[i]<<"	"<<b[i]<<"	"<<endl;
	}

}

int counter=0;
int main()
{
	int i,j;
	int a[5],b[5];
	int tat[5];
	int ctime[5];
	int wt[5];
	int index;
	int temp1,temp2;
	/*
	for(i=0;i<6;i++)
	{
		cin>>a[i]>>b[i];
	}
	*/
	a[0]=getArrivalTime("input1.txt");
	a[1]=getArrivalTime("input5.txt");
	a[2]=getArrivalTime("input4.txt");
	a[3]=getArrivalTime("input3.txt");
	a[4]=getArrivalTime("input2.txt");
	b[0]=getBurstTime("input1.txt");
	b[1]=getBurstTime("input5.txt");
	b[2]=getBurstTime("input4.txt");
	b[3]=getBurstTime("input3.txt");
	b[4]=getBurstTime("input2.txt");
	print(a,b);
	cout<<"\n\n";
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp1=a[j];
				a[j]=a[j+1];
				a[j+1]=temp1;
				temp2=b[j];
				b[j]=b[j+1];
				b[j+1]=temp2;
			}	
		}
	}
	int rt[5];
	for(i=0;i<5;i++)
	{
		rt[i]=b[i];
		cout<<rt[i]<<endl;
	}
	print(a,b);
	int time = a[0];
	cout<<time<<endl;
	int count=0;
	int mark=0;
	int req;
	for(time=a[0];count<5;time++)
	{
		//cout<<time<<endl;
		//cout<<count<<endl;
		for(i=mark;i<5;i++)
		{
			if(time>=a[i])
			{
				mark=i;
			}
		}
		int min=10000;
		for(j=mark;j>=0;j--)
		{
			if(b[j]==0)
			{
				goto l;
			}
			if(b[j]<=min)
			{
				min=b[j];
				req=j;
			}
			l:;
		}
		cout<<req+1<<" ";
		b[req]--;
		if(b[req]==0)
		{
			count++;
			ctime[req]=time+1;
		}
	}
	cout<<endl;
	float k;
	for(i=0;i<5;i++)
	{
		tat[i]=ctime[i]-a[i];
		wt[i]=tat[i]-rt[i];
		cout<<ctime[i]<<"	"<<tat[i]<<"	"<<wt[i]<<"	"<<endl;
	}
	//print()
	return 0;
}

