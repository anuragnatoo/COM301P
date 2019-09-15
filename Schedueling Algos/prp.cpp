#include<bits/stdc++.h>
#include <sys/stat.h>
#include <time.h>
#include<fstream>
using namespace std;
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
int getArrivalTime(string s)
{
	struct tm* timevar;
	struct stat filedetail;
	stat(s.c_str(), &filedetail);
	timevar = gmtime(&(filedetail.st_mtime));
	int at=timevar->tm_sec;
	return at;
}
void print(int a[],int b[])
{
	int i;
	for(i=0;i<6;i++)
	{
		cout<<a[i]<<"	"<<b[i]<<"	"<<endl;
	}
}
int findHighestPriority(int a[])
{
	int max=0;
	//cout<<max<<endl;
	int maxi=0;
	int i;
	for(i=0;i<5;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			maxi=i;
		}
	}
	return maxi;
}
int main()
{
	int i,j;
	int temp1,temp2,temp3;
	int a[6],b[6];
	int ctime[6];
	int highpriorindex=0;
	int prior[6];
	int priorcopy[6];
	int tat[6];
	int wt[6];
	int burstcopy[6];
	a[0]=getArrivalTime("input1.txt");
	a[1]=getArrivalTime("input5.txt");
	a[2]=getArrivalTime("input4.txt");
	a[3]=getArrivalTime("input3.txt");
	a[4]=getArrivalTime("input2.txt");
	a[5]=getArrivalTime("input6.txt");
	b[0]=getBurstTime("input1.txt");
	b[1]=getBurstTime("input5.txt");
	b[2]=getBurstTime("input4.txt");
	b[3]=getBurstTime("input3.txt");
	b[4]=getBurstTime("input2.txt");
	b[5]=getBurstTime("input6.txt");
	/*
	for(i=0;i<6;i++)
	{
		cin>>a[i]>>b[i];
		burstcopy[i]=b[i];
	}
	*/
	for(i=0;i<6;i++)
	{
		burstcopy[i]=b[i];
	}
	print(a,b);
	cout<<"Enter the priorities of the processes--"<<endl;
	for(i=0;i<6;i++)
	{
		cout<<"Burst time-"<<b[i]<<endl;
		cout<<"Enter the priority!";
		cin>>prior[i];
		priorcopy[i]=prior[i];
	}
	for(i=0;i<6;i++)
	{
		cout<<priorcopy[i]<<endl;
	}
	int timecounter=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp1=a[j];
				a[j]=a[j+1];
				a[j+1]=temp1;
				temp2=b[j];
				b[j]=b[j+1];
				b[j+1]=temp2;
				temp3=prior[j];
				prior[j]=prior[j+1];
				prior[j+1]=temp3;
			}
		}
	}
	for(i=0;i<6;i++)
	{
		burstcopy[i]=b[i];
	}
	for(i=0;i<6;i++)
	{
		cout<<"Arrival Time--"<<a[i]<<"	"<<"Burst time--"<<b[i]<<"		"<<"Priority--"<<prior[i]<<endl;
	}
	timecounter = a[0];
	/*
	for(i=0;i<5;i++)
	{
		if(a[i]<=timecounter)
		{
			highpriorindex=findHighestPriority(prior);
			cout<<highpriorindex<<endl;
			timecounter=timecounter+b[highpriorindex];
			cout<<timecounter<<endl;
			ctime[highpriorindex]=timecounter;
			cout<<"a time--"<<a[highpriorindex]<<"	"<<"b time--"<<b[highpriorindex]<<"	"<<"	"<<"C Time-"<<ctime[highpriorindex]<<endl;
			prior[highpriorindex]=-1;
		}
	}
	*/
	int total=0;
	int pro[6];
	int cpro=0;
	int inpri=0;
	while(total!=6)
	{
		cpro=0;
		i=0;
		while(i<6)
		{
			if(a[cpro]<=timecounter)
			{
				pro[cpro]=cpro;
				cpro++;
			}
			i++;
		}
		int max=0;
		for(i=0;i<cpro;i++)
		{
			if(prior[pro[i]]>max)
			{
				max=prior[pro[i]];
				inpri=pro[i];
			}
		}
		/*
		timecounter=timecounter+b[inpri];
		ctime[inpri]=timecounter;
		cout<<"a time--"<<a[inpri]<<"	"<<"b time--"<<b[inpri]<<"	"<<"	"<<"C Time-"<<ctime[inpri]<<endl;
		prior[inpri]=-1;
		*/
		timecounter++;
		b[inpri]--;
		if(b[inpri]==0)
		{
			ctime[inpri]=timecounter;
			cout<<"a time--"<<a[inpri]<<"	"<<"b time--"<<burstcopy[inpri]<<"	"<<"	"<<"C Time-"<<timecounter<<endl;
			prior[inpri]=-1;
			total++;
		}
	}
	for(i=0;i<6;i++)
	{
		tat[i]=ctime[i]-a[i];
		wt[i]=tat[i]-burstcopy[i];
		cout<<"Turn around time--"<<tat[i]<<"	"<<"Weight Time--"<<wt[i]<<endl;
	}
	float avg;
	int sum=0;
	for(i=0;i<6;i++)
	{
		sum=sum+wt[i];
	}
	avg=(float)sum/6;
	cout<<"Average Weight time--"<<avg<<endl;
	return 0;
}
