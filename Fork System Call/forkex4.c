#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<sys/wait.h> 
/*
Question 4:
Ascending Order sort within Parent and Descending order sort  (or vice versa) within the child process of an input array.
*/
int main() 
{
	int a[6];
	int i,j;
	int swap;
	//cout<<"Enter 6 numbers\n";
	printf("Enter 6 numbers \n");
	for(i=0;i<6;i++)
	{
		scanf("%d",&a[i]);
	}
	int pid=fork();
	if(pid==0)
	{
		wait(NULL);
		for(i=0;i<5;i++)
		{
			for(j=0;j<5-i;j++)
			{
				if(a[j]>a[j+1])
				{
					swap=a[j];
					a[j]=a[j+1];
					a[j+1]=swap;
				}
			}
		}
		printf("Ascending order\n");
		for(i=0;i<6;i++)
		{
			printf("%d\n",a[i]);
		}
		printf("\n\n");
	}
	else
	{
		//wait(NULL);
		for(i=0;i<5;i++)
		{
			for(j=0;j<5-i;j++)
			{
				if(a[j]<a[j+1])
				{
					swap=a[j];
					a[j]=a[j+1];
					a[j+1]=swap;
				}
			}
		}
		printf("Descending order\n");
		for(i=0;i<6;i++)
		{
			//cout<<a[i]<<<endl;
			printf("%d\n",a[i]);
		}
	
	}
    return 0; 
} 
