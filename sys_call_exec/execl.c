#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
   		fprintf(stderr, "fork failed");
   		return 1;    
   	}
	else if(pid == 0)
	{  
   		execl("/bin/ls", "ls -1", NULL);
      	printf("parent complete\n");
   	}
	else
	{
   		wait(NULL);
   		printf("child complete\n");
   	}
	return 0;
}
