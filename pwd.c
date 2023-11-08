#include "header.h"
void pwd()
{
    char s1[100];
    /*int fd;
    if (output == 1)
    {
        //k=k-2;
        fd = open(reout, O_WRONLY | O_CREAT, 0644);
        if (fd < 0)
        {
            perror("");
            exit(0);
        }
        dup2(fd,1);
        return;
    }
    else if (output == 2)
    {
        //k=k-2;
        fd = open(reout, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd < 0)
        {
            perror("");
            exit(0);
        }
        dup2(fd,1);

        //count++;
    }*/
    printf("%s\n", getcwd(s1, 100));
    return;
}