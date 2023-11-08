#include "header.h"
void pinfo(char *arr[], int k)
{
    char path[10000];
    pid_t pid;
    if (k == 1)
    {
        pid = getpid();
    }
    else
    {
        if (strcmp(arr[1], "&") == 0)
        {
            pid = atoi(arr[2]);
        }
        else
        {
            pid = atoi(arr[1]);
        }
    }
    if (pid == 0)
    {
        printf("Invalid pid\n");
        return;
    }
    if (kill(pid, 0))
    {
        perror("Invalid pid\n");
    }
    else
    {
        printf("Pid--  %d\n", pid);
        sprintf(path, "/proc/%d/status", pid);
        int fd = open(path, O_RDONLY);
        if (fd < 0)
        {
            perror("Error:");
        }
        else
        {
            char size[100];

            FILE *fileptr;
            fileptr = fopen(path, "r");
            if(fileptr==NULL)
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
                    printf("%s", size);
                }

                if (count_lines == 18)
                {
                    char *token = strtok(size, ":");
                    //printf("%s\n", token);
                    while (token != NULL)
                    {
                        if (strcmp(token, "VmSize") != 0)
                        {
                            printf("Memory -- %s\n", token);
                            break;
                        }
                        token = strtok(NULL, ":");
                    }
                }
                //printf("\n");
            }
            sprintf(path, "/proc/%d/exe", pid);
            char size1[100];
            readlink(path, size1, 1000);
            printf("Executable Path -- %s\n", size1);
            fclose(fileptr);
            //printf("Hi broh\n");
        }
    }
}