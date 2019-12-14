#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<wait.h>
#define BS 20
int main(void)
{
    //Q6: BiDirectional Pipe

	char wmp[BS];
	char rmp[BS];
	char wmc[BS];
	char rmc[BS];

	int fd1[2], fd2[2];

	pipe(fd1);
	pipe(fd2);

	pid_t pid;
	pid = fork();

	if(pid>0)
	{

		printf("Parent Message for Child ");
		scanf("%[^\n]", wmp);
		close(fd1[0]);
		close(fd2[1]);
		write(fd1[1], wmp, strlen(wmp)+1);
		read(fd2[0], rmp, BS);
		close(fd1[1]);
		close(fd2[0]);
		printf("Parent Message from Child: %s\n", rmp);
	}
	else if(pid==0){

		printf("Then Child Message for Parent Respectively:\n");

		scanf("%[^\n]", wmc);
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0], rmc, BS);
		write(fd2[1], wmc, strlen(wmc)+1);
		close(fd1[0]);
		close(fd2[1]);

		printf("Child Message from Parent: %s\n", rmc);
	}
    return 0;
}
