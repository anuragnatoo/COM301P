#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<sys/wait.h> 
/*
Question 2:
Odd and Even series generation using Parent Child relationship
*/
int main() 
{
	int n;
	int i;
	printf("Enter the range\n");
	scanf("%d",&n);
	int pid=fork();
	if(pid==0)
	{
		//wait(NULL);
		for(i=0;i<n;i++)
		{
			if(i%2==0)
			{
				printf("%d\n",i);
			}
		}
		printf("\n\n");
	}
	else
	{
		wait(NULL);
		for(i=0;i<n;i++)
		{
			if(i%2!=0)
			{
				printf("%d\n",i);
			}
		}
		printf("\n\n");
	}
    return 0; 
} 
