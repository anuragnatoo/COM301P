#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include <pthread.h>
void* catcommand(void* param);
void* catcommand2(void* param);
struct args {
    char* cmd;
    char* file1;
    char* file2;
};
int main(int argc, char *argv[]) 
{
	//char *args[]={argv[1],argv[2],argv[3],NULL};
	struct args arguments;
	//struct args *arguments = (struct args *)malloc(sizeof(struct args));
    //execvp(args[0],args);  
    //printf("Ending-----"); 
    printf("\n\n");
    arguments.cmd=argv[1];
    arguments.file1=argv[2];
    arguments.file2=argv[3];
    pthread_t tid;
    pthread_t tid1;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,catcommand,(void *)&arguments);
	pthread_join(tid,NULL);
    return 0; 
}
void* catcommand(void* param)
{
	struct args *arguments=param;
	char *args[]={arguments->cmd,arguments->file1,arguments->file2,NULL};
	execvp(args[0],args);
	pthread_exit(0);
}
