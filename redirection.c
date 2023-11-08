#include "header.h"
#include "functions.h"

void redirection(char *arr[], int k, int o, char *sym)
{
    int fd;

    if (o == 1)
    {
        fd = open(arr[2], O_WRONLY | O_CREAT, 0644);
    }
    if (o == 2)
    {
        fd = open(arr[2], O_APPEND | O_WRONLY | O_CREAT, 0644);
    }
    if(fd<0)
    {
        perror("failed");
    }
    int original=1;
    printf("%d\n",STDOUT_FILENO);

    dup2(1,original);
    if(dup2(fd, STDOUT_FILENO)<0)
    {
      perror("File not found\n");
      exit(1);
    }
    close(fd);
    //printf("Where am i\n");
    ///file(arr, k, sym);
    if (strcmp(arr[0], "pwd") == 0)
    {
        pwd();
        //cdpwd[0] = getcwd(s, 100);
    }
    else if (strcmp(arr[0], "echo") == 0)
    {
        echo(arr, k - 1);
        printf("%d\n",original);
        dup2(original,STDOUT_FILENO);

    }
    else if (strcmp(arr[0], "history") == 0)
    {
        if (k == 1)
        {
            //printf("hello1");
            history(path);
        }
        else
        {
            //printf("hello2");
            history_num(arr[1], path);
        }
        //printf("\n");
    }
    else if (strcmp(arr[0], "pinfo") == 0)
    {
        pinfo(arr, k - 1);
        //break;
    }
    else if (strcmp(arr[0], "repeat") == 0)
    {
        repeat(arr, k - 1);
    }
    else if (strcmp(arr[0], "ls") == 0)
    {
        ls(sym, arr, k - 1);
    }
    else
    {
        processes(arr, k - 1);
        //printf("broh im there\n");
    }
    return;
}