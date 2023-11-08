#include "header.h"
pid_t pid;
void background(char *ar[],int n)
{
	//printf("%d\n",n);
	ar[n-1]=NULL;
	pid=fork();
	setpgid(0,0);
	if (pid<0)
	{
		perror("Fork failed");
	}
	else if(pid==0)
	{
		//printf("Broh i here\n");
		pid_t p =getpid();
		//printf("%d\n",p);
		int a= execvp(ar[0],ar);
		if (a<0)
		{
			perror("Error");
		}
		if(strcmp(ar[0],"vim")==0)
		{
			kill(p,19);
		}
		exit(0);
	}
	else{
		jc++;
		printf("[%d] %d %s\n",jc,pid,ar[0]);
		ja[jc].pid=pid;
		strcpy(ja[jc].nme,ar[0]);
		//exit(0);
	}
	return;
}
void foreground(char *ar[], int k)
{
	//pid_t pid;
	//printf("I am in fg\n");

	pid = fork();
	cf.pid=pid;
	strcpy(cf.nme,ar[0]);
	
	if (pid == 0)
	{
		//pid_t p = getpid();

		int x = execvp(ar[0], ar);

		if (x < 0)
		{
			printf("Command not found: %s\n", ar[0]);
		}
		exit(0);
	}
	else
	{
		int s;
		waitpid(pid,&s,WUNTRACED);
			//return;
	}
	return;
}
