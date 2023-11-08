/*#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
    if(argc!=2)
    {
        printf("Usage: %s filename\n",argv[0]);
    }
    int o;
    int fd=open(argv[1],O_WRONLY | O_CREAT,0644);
    if(fd<0)
    {
        perror("failed");
        exit(1);
    }
    printf("I am on screen\n");
    dup2(STDOUT_FILENO,o);
    if(dup2(fd,STDOUT_FILENO)<0)
    {
        perror("error");
        exit(1);
    }
    close(fd);
    printf("whr am i\n");
    dup2(o,STDOUT_FILENO);
    printf("i am on terminal\n");
    return 0;
}*/
// C program to illustrate
// pipe system call in C
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MSGSIZE 16
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main()
{
	char inbuf[MSGSIZE];
	int p[2], i;

	if (pipe(p) < 0)
		exit(1);

	/* continued */
	/* write pipe */

	write(p[1], msg1, MSGSIZE);
	write(p[1], msg2, MSGSIZE);
	write(p[1], msg3, MSGSIZE);

	for (i = 0; i < 3; i++) {
		/* read pipe */
		read(p[0], inbuf, MSGSIZE);
		printf("%s\n", inbuf);
	}
	return 0;
}
