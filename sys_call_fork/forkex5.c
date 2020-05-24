#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<sys/wait.h> 
int main() 
{
	int n;
	printf("Enter n\n");
	scanf("%d",&n);
	int a[n];
	int i,j;
	int swap;
	//cout<<"Enter 6 numbers\n";
	printf("Enter %d numbers \n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int pid=vfork();
	if(pid==0)
	{
		//wait(NULL);
		for(i=0;i<n/2;i++)
		{
			for(j=i+1;j<n/2;j++)
			{
				if(a[i]>a[j])
				{
					swap=a[i];
					a[i]=a[j];
					a[j]=swap;
				}
			}
		}
		printf("Ascending order\n");
		for(i=0;i<n/2;i++)
		{
			printf("%d\n",a[i]);
		}
		printf("\n\n");
		exit(0);
	}
	else
	{
		//wait(NULL);
		for(i=n/2;i<n-1;i++)
		{
			for(j=i+1;j<n-1;j++)
			{
				if(a[i]>a[j])
				{
					swap=a[i];
					a[i]=a[j];
					a[j]=swap;
				}
			}
		}
		printf("Descending order\n");
		for(i=n-1;i>=n/2;i--)
		{
			//cout<<a[i]<<<endl;
			printf("%d\n",a[i]);
		}
	
	}
    return 0; 
} 
