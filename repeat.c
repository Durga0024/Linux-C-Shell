#include "header.h"

int repeat(char* arr[],int k)
{
    //printf("k=%d\n",k);
    char s[100];
    int n=atoi(arr[1]);
    if(strcmp(arr[2],"cd")==0)
    {
        for(int i =0;i<n;i++)
        {
            chdir(arr[3]);
        }
        printf("%s\n",getcwd(s,100));
    }
    else if(strcmp(arr[2],"echo")==0)
    {
        //printf("a:%s\n",arr[3]);
        for(int i =1;i<=n;i++)
        {
            for(int j=3;j<k;j++)
                printf("%s ",arr[j]);
            printf("\n");
            //printf("hi\n");
        }
    }
    else if(strcmp(arr[2],"sleep")==0)
    {
        int l=atoi(arr[3]);
        for(int i =0;i<n;i++)
        {
            sleep(l);
        }
    }
}