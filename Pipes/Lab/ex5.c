#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define BS 20
//--------------Word Count Question---------------
int main()
{
	printf("-----------Word Count from a text file--------------\n");
	char wm[BS];
	char rm[BS];	
	int fd[2];
	pipe(fd);
	FILE *fp;
	pid_t pid = fork();
	if(pid<0)
		printf("failed to fork\n");
	else if(pid==0)
	{
		char ch[1];
		close(fd[0]);
		fp= fopen("textwc.txt", "r");
		while(!feof(fp))
		{
			ch[0] = fgetc(fp);
			write(fd[1], ch, 1);
		}
		fclose(fp);
		close(fd[1]);
	}
	else if(pid>0)
	{
		int nc=0, nw=0, nl=0, ns=0;
		char rec[1];
		close(fd[1]);
		while(read(fd[0], rec, 1)>0)
		{
			nc++;
			//printf("%c-->%d\n", rec[0], nc );
			//if(rec[0]=='.')
				//ns++;
			if(rec[0]=='\n')
				nl++;
			if(rec[0]==' ' || rec[0] == '\n')
				nw++;
		}
		//printf("%c %d\n", rec[0], rec[0] );
		//nw++;
		nc--;
		close(fd[0]);
		printf("wc -c: %d\twc -l: %d\twc -w :%d\t\n", nc, nl, nw);
		return 0;
	}
}
