#include "header.h"

void history(char *path)
{
    /*int fd,sz;
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
    //int n = atoi(arr);
    //if (strcmp(arr,"\0") == 0)

    FILE *fileptr;
    fileptr = fopen(path, "r");
    char chr = getc(fileptr);
    int count_lines = 0;
    while (chr != EOF)
    {
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        chr = getc(fileptr);
    }
    fclose(fileptr);
    int a = count_lines - 20;
    if (a < 0)
    {
        a = count_lines;
    }

    FILE *file = fopen(path, "r");
    char ch = getc(file);
    int count = 0;
    while (ch != EOF)
    {
        if (a <= count)
        {
            //if (!output)
            printf("%c", ch);
            /*else if (output)
            {
                //printf("%s", arr[j]);
                sz = write(fd, ch, 1);
            }*/
        }
        if (ch == '\n')
        {
            count = count + 1;
        }
        ch = getc(file);
    }
    fclose(file);

    // else{
    // return;
    // }
    /*char c = fgetc(file);
    char *arri = arr;
    printf("%s", arri);
    if (arr != 0)
    {
        int j = 0;
        int x = atoi(arri);
        while (c != EOF)
        {
            char string[100];
            printf("%c", c);
            if (c == '\n')
            {
                j++;
            }
            if (j == x)
            {
                break;
            }
            c = fgetc(file);
        }
    }
    else
    {
        while (c != EOF)
        {
            char string[100];
            printf("%c", c);
            c = fgetc(file);
        }
    }*/
}
void history_num(char *arr, char *path, int output)
{
    int fd,sz;
    int n = atoi(arr);
    FILE *fileptr;
    fileptr = fopen(path, "r");
    char chr = getc(fileptr);
    int count_lines = 0;
    while (chr != EOF)
    {
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        chr = getc(fileptr);
    }
    fclose(fileptr);
    int a = count_lines - n;
    if (a < 0)
    {
        //if (!output)
        printf("Too many lines");
        /*else if (output)
        {
            //printf("%s", arr[j]);
            sz = write(fd,"Too many lines", strlen("Too many lines"));
        }
        printf("Too many lines");
        return;*/
    }

    FILE *file = fopen(path, "r");
    char ch = getc(file);
    int count = 0;
    while (ch != EOF)
    {
        if (a <= count)
        {
            //if (!output)
                printf("%c", ch);
            /*else if (output)
            {
                //printf("%s", arr[j]);
                sz = write(fd, ch, strlen(ch));
            }*/
        }
        if (ch == '\n')
        {
            count = count + 1;
        }
        ch = getc(file);
    }
    fclose(file);
}
