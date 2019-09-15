#include<bits/stdc++.h>
#include <sys/stat.h>
#include <time.h>
#include<fstream>
using namespace std;
int getArrivalTime(string s);
int getBurstTime(string s);
void fcfs(int a[],int b[]);
void print(int a[],int b[]);
void sortArrivalTimes(int a[],int b[]);
int main()
{
	int a[5],b[5];
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
	cout<<"Arrival times and Burst times\n";
	print(a,b);
	cout<<endl;
	cout<<endl;
	cout<<"After sorting"<<endl;
	fcfs(a,b);
	return 0;
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
void fcfs(int a[],int b[])
{
	int i;
	int ctime[5],tat[5],wt[5];
	int sum=0;
	sortArrivalTimes(a,b);
	print(a,b);
	cout<<endl;
	cout<<endl;
	ctime[0]=0;
	//cout<<a[0]<<
	ctime[0]=a[0]+b[0];
	for(i=1;i<5;i++)
	{
		ctime[i]=b[i]+ctime[i-1];
	}
	for(i=0;i<5;i++)
	{
		tat[i]=ctime[i]-a[i];
		wt[i]=tat[i]-b[i];
		sum=sum+wt[i];
	}
	for(i=0;i<5;i++)
	{
		cout<<a[i]<<"	"<<b[i]<<"	"<<ctime[i]<<"	"<<tat[i]<<"	"<<wt[i]<<endl;
	}
}
void sortArrivalTimes(int a[],int b[])
{
	int i;
	int j;
	int swap1,swap2;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if(a[j]>a[j+1])
			{
				swap1=a[j];
				a[j]=a[j+1];
				a[j+1]=swap1;
				swap2=b[j];
				b[j]=b[j+1];
				b[j+1]=swap2;
			}
		}
	
	}

}
void print(int a[],int b[])
{
	int i;
	for(i=0;i<5;i++)
	{
		cout<<a[i]<<"	"<<b[i]<<"	"<<endl;
	}

}

