#include "header.h"
int echo(char *arr[], int k)
{
    //printf("%d\n",k);
    /*int fd;
    if (output == 1)
    {
        k=k-2;
        fd = open(reout, O_WRONLY | O_CREAT, 0644);
        if (fd < 0)
        {
            perror("");
            exit(0);
        }
        dup2(fd,1);
    }
    else if (output == 2)
    {
        k=k-2;
        fd = open(reout, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd < 0)
        {
            perror("");
            exit(0);
        }
        dup2(fd,1);

        //count++;
    }*/

    int j;
    for (j = 1; j < k; j++)
    {
        if (j == k - 1)
        {
            printf("%s\n", arr[j]);
        }
        else
        {

            printf("%s ", arr[j]);
            /*else if (output)
            {
                //printf("%s", arr[j]);
                int sz = write(fd, arr[j], strlen(arr[j]));
            }*/
        }
    }
    
}
