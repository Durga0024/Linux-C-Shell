#include "header.h"
int changedir(char* arr,char* sym,int k,char* cdpwd,char* sy)
{
    char s[100];
    if (k == 1)
    {
        arr = sym;
    }
    //printf("%s\n",arr[1]);
    if (strcmp(arr, "-") == 0)
    {
        //printf("%s\n--",sy[0]);
        printf("%s\n", cdpwd);
        chdir(cdpwd);
        sy = getcwd(s, 100);
    }
    else if (strcmp(arr, "--") == 0 || strcmp(arr, "~") == 0)
    {
        chdir(sym);
        sy = getcwd(s, 100);
        cdpwd = getcwd(s, 100);
    }
    else
    {
        int er = chdir(arr);
        if (er != 0)
        {
            printf("No such file or directory\n");
        }
        else
        {
            sy = getcwd(s, 100);
            cdpwd= getcwd(s, 100);
        }
    }
    if (k > 2)
    {
        printf("To many arguments\n");
    }
    return 0;
}