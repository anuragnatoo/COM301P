#include<bits/stdc++.h>
#include <sys/stat.h>
#include <time.h>
#include<fstream>
using namespace std;
int getArrivalTime(string s);
int getBurstTime(string s);
void print(int a[],int b[]);
int findminArrival(int a[]);
int findminBurstTime(int b[],int a[],int count);
//void sortArrivalTimes(int a[],int b[]);
int counter=0;
int main()
{
	int a[5],b[5];
	//int tat[5];
	//int wt[5];
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
	//fcfs(a,b);
	int ctime[5],tat[5],wt[5];
	int i=findminArrival(a);
	int j=i;
	int k;
	//cout<<i<<endl;
	cout<<endl;
	ctime[i]=a[i]+b[i];
	tat[i]=ctime[i]-a[i];
	wt[i]=tat[i]-b[i];
	cout<<a[i]<<"	"<<b[i]<<"	"<<ctime[i]<<"	"<<tat[i]<<"	"<<wt[i]<<endl;
	a[i]=20000;
	b[i]=300000;
	int index;
	counter=counter+ctime[i];
	for(k=0;k<5;k++)
	{
		if(k!=j)
		{
			index=findminBurstTime(b,a,counter);
			ctime[index]=counter+b[index];
			counter=counter+b[index];
			tat[index]=ctime[index]-a[index];
			wt[index]=tat[index]-b[index];
			cout<<a[index]<<"	"<<b[index]<<"	"<<ctime[index]<<"	"<<tat[index]<<"	"<<wt[index]<<endl;
			b[index]=300000;
			a[i]=20000;
		}
	}
	return 0;
}
int findminArrival(int a[])
{
	int i;
	int min=a[0];
	int mini=0;
	for(i=0;i<5;i++)
	{
		if(min>a[i]){
			min=a[i];
			mini=i;
		}
	}
	//a[mini]=20000;
	return mini;
}
int findminBurstTime(int b[],int a[],int count)
{
	int i;
	int min=200000;
	int mini=0;
	for(i=0;i<5;i++)
	{
		if(a[i]<=count)
		{
			if(b[i]<min)
			{
				min=b[i];
				mini=i;
			}
		}
	}
	//b[mini]=300000;
	//a[mini]=20000;
	return mini;
}
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
	for(i=0;i<5;i++)
	{
		cout<<a[i]<<"	"<<b[i]<<"	"<<endl;
	}

}


