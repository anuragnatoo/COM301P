#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() 
{ 

        char *args[]={"ls -l",NULL}; 
        execvp(*args,args);    
        printf("Ending-----"); 
      
    return 0; 
} 
