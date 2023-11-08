#include "header.h"
#include "functions.h"
void jobs(char *a[], int n)
{
    //printf("I m in %d\n", jc);

    for (int i = 1; i <= jc; i++)
    {
        long long int pid = ja[i].pid;
        char nam[10000], file[10000], status, st[10000];
        strcpy(nam, ja[i].nme);
        sprintf(file, "/proc/%lld/status", pid);
        char size[100];
        FILE *fileptr;
        fileptr = fopen(file, "r");
        if (fileptr == NULL)
        {
            perror("File not found");
            return;
        }
        //char chr = getc(fileptr);
        int count_lines = 0;
        while (fgets(size, sizeof(size), fileptr))
        {
            count_lines++;

            if (count_lines == 3)
            {
                //printf("s=%s\n", size);

                char *t = strtok(size, " ");
                //printf("s=%s\n", size);

                while (t != NULL)
                {
                    if (size[0]=='T')
                    {
                        strcpy(st, "Stopped");
                    }
                    else
                    {
                        strcpy(st, "Running");
                    }
                    t = strtok(NULL, " ");
                }
            }
        }
        fclose(fileptr);

        if (k == 1)
            printf("[%d] %s %s [%lld]\n", i, st, nam, pid);
        else if (strcmp(a[1], "-r") == 0)
        {
            if (strcmp(st, "Running") == 0)
                printf("[%d] %s %s [%lld]\n", i, st, nam, pid);
            else
            {
                printf("There are no jobs\n");
            }
        }
        else if (strcmp(a[1], "-s") == 0)
        {
            if (strcmp(st, "Stopped") == 0)
                printf("[%d] %s %s [%lld]\n", i, st, nam, pid);
            else
            {
                printf("There are no jobs\n");
            }
        }
        else
        {
            printf("Invalid Flag\n");
        }
    }
    return;
}

void sigjobs(char *ar[], int n)
{
    if (n != 3)
    {
        printf("Error: Incorrect number of arguments\n");
        exit(1);
    }
    int num, signo;
    num = atoi(ar[1]);
    signo = atoi(ar[2]);
    //printf("%d\n",signo);
    int f = 0;

    if (signo == 9)
        kjb=1;
    if (num <= jc && num > 0)
        kill(ja[num].pid, signo);
    else
        printf("Error: No such process found\n");
}

void bg(char *ar[])
{
    if (k == 1)
    {
        printf("To few arguments\n");
        display(sym[0]);
    }
    int num = atoi(ar[1]);
    int flag = 0;
    for (int i = 1; i <= jc; i++)
    {
        if (i == num)
        {
            flag = 1;
            kill(ja[num].pid, SIGTTIN);
            kill(ja[num].pid, SIGCONT);
        }
    }
    if (flag == 0)
    {
        printf("Error: NO such job found\n");
    }
}
void fg(char *ar[])
{
    if (k == 1)
    {
        printf("To few arguments\n");
    }
    int num = atoi(ar[1]);
    int flag = 0;
    for (int i = 1; i <= jc; i++)
    {
        if (i == num)
        {
            int status;
            signal(SIGTTIN, SIG_IGN);
            signal(SIGTTOU, SIG_IGN);
            tcsetpgrp(STDIN_FILENO, ja[num].pid);
            flag = 1;
            cf.pid = ja[num].pid;
            strcpy(cf.nme, ja[num].nme);
            kill(ja[num].pid, SIGCONT);
            delprocess(ja[num].pid);
            waitpid(-1, NULL, WUNTRACED);
            tcsetpgrp(STDIN_FILENO, getpgrp());
            signal(SIGTTIN, SIG_DFL);
            signal(SIGTTOU, SIG_DFL);
        }
    }
    if (flag == 0)
    {
        printf("Error: NO such process found\n");
    }
}
void overkill()
{
    for(int i=1;i<=jc;i++)
    {
        kill(ja[i].pid,9);
    }
    ok=1;
}