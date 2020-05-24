#include<stdio.h>
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{
    int pid=fork(); 
    if(pid>0)
    {
        printf("In Parent Process");
    }    
    else if (pid == 0) 
    { 
    	printf("%d\n",getppid());
        sleep(3);
        printf("In Child Process");
        printf("%d\n",getppid());
    }   
    return 0; 
}
