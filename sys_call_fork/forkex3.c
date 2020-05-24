#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<sys/wait.h> 
/*
Question-3:
Fibonacci Series generation using parent child relationship.
*/
int main() 
{
	int n;
	int i;
	//printf("Enter the range\n");
	//scanf("%d",&n);
	int fib[100];
	int pid=vfork();
	if(pid==0)
	{
		printf("Enter the range\n");
		//wait(NULL);
		scanf("%d",&n);
		printf("Child Process\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		printf("Parent Process\n");
		//printf("%d\n",n);
		fib[0]=1;
		fib[1]=1;
		for(i=2;i<n;i++)
		{
			fib[i]=fib[i-1]+fib[i-2];
			printf("%d\n",fib[i]);
		}
		printf("\n\n");
	}
    return 0; 
} 
