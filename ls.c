#include "header.h"

void lsa(char *dir)
{
    DIR *d;
    struct dirent **read;
    long long x = 0, n = scandir(dir, &read, NULL, alphasort);
    if (n < 0)
        perror("Error:\n");
    else
    {
        while (x < n)
        {
            printf("%s\n", read[x++]->d_name);
        }
    }
}

void lsla(char* dir,int flag)
{
    //printf("%s\n",dir);

    DIR *d;
    struct dirent **read;
    long long x = 0, n = scandir(dir, &read, NULL, alphasort);

    if (n < 0)
        perror("Error: \n");
    else
    {
        while (x < n)
        {
            char path[10000];
            struct stat s;
            strcpy(path, read[x++]->d_name);

            if (path[0] == '.' && flag == 0)
                continue;
            else
            {
                char per[20] = "";
                char own[10], ug[10], date[30], time[6], path2[10000];
                long long hardlinks, size;
                strcpy(path2,"");
                strcat(path2, dir);
                strcat(path2, "/");
                strcat(path2, path);

                stat(path2, &s);

                hardlinks = s.st_nlink;

                struct passwd *pd;
                pd = getpwuid(s.st_uid);
                struct group *gr;
                gr = getgrgid(s.st_gid);

                size = s.st_size;
                

                if (S_ISDIR(s.st_mode) ? strcat(per, "d") : strcat(per, "-"));
                if ((s.st_mode & S_IRUSR) ? strcat(per, "r") : strcat(per, "-"));
                if ((s.st_mode & S_IWUSR) ? strcat(per, "w") : strcat(per, "-"));
                if ((s.st_mode & S_IXUSR) ? strcat(per, "x") : strcat(per, "-"));
                if ((s.st_mode & S_IRGRP) ? strcat(per, "r") : strcat(per, "-"));
                if ((s.st_mode & S_IWGRP) ? strcat(per, "w") : strcat(per, "-"));
                if ((s.st_mode & S_IXGRP) ? strcat(per, "x") : strcat(per, "-"));
                if ((s.st_mode & S_IROTH) ? strcat(per, "r") : strcat(per, "-"));
                if ((s.st_mode & S_IWOTH) ? strcat(per, "w") : strcat(per, "-"));
                if ((s.st_mode & S_IXOTH) ? strcat(per, "x") : strcat(per, "-"));
                strftime(date, 24, "%Y-%m-%d    %H:%M", localtime(&(s.st_ctime)));

                printf("%-12s%-6lld%-8s%-8s%-8lld%-24s%-20s\n", per, hardlinks, pd->pw_name, gr->gr_name, size, date, path);
            }            
        }
    }
    return;
}

void justls(char *dir)
{
    
    DIR *d;
    struct dirent **read;
    long long x = 0, n = scandir(dir, &read, NULL, alphasort);
    if (n < 0)
        perror("Error:\n");
    else
    {
        while (x < n)
        {
            if(read[x]->d_name[0]!='.')
            {
                printf("%s\n", read[x]->d_name);
                x++;
            }
            else{
                x++;
            }
        }
    }
}

void ls(char *dir, char *arr[], int k)
{
    //printf("1:%s\n",dir);

    if (k == 1)
    {
        printf("ls:");
        char* x = ".";
        justls(x);
    }
    else if (k == 2 && strcmp(arr[1], "-a") == 0)
        lsa(dir);
    else if (k == 2 && strcmp(arr[1], "-l") == 0)
        lsla(dir, 0);
    else if (k == 2 && ((strcmp(arr[1], "-la") == 0) || strcmp(arr[1], "-al") == 0))
        lsla(dir, 1);
    else if (k==2 && strcmp(arr[1],"~")==0)
        justls(dir);
    else if (k == 2)
        justls(arr[1]);
    else if (k == 3 && (strcmp(arr[1], "-a") == 0 && strcmp(arr[2], "-l") == 0) || (strcmp(arr[2], "-a") == 0 && strcmp(arr[1], "-l") == 0))
        lsla(dir, 1);
    else if (k == 3 && ((strcmp(arr[1], "-l") == 0) && (strcmp(arr[2], "-l") != 0) && (strcmp(arr[2], "-a") != 0)) || ((strcmp(arr[2], "-l") == 0) && (strcmp(arr[1], "-l") != 0) && (strcmp(arr[1], "-a") != 0)))
    {
        if (strcmp(arr[1], "-l") == 0)
            lsla(arr[2], 0);
        else
            lsla(arr[1], 0);
    }
    else if (k == 3 && ((strcmp(arr[1], "-a") == 0) && (strcmp(arr[2], "-l") != 0) && (strcmp(arr[2], "-a") != 0)) || ((strcmp(arr[2], "-a") == 0) && (strcmp(arr[1], "-l") != 0) && (strcmp(arr[1], "-a") != 0)))
    {
        if (strcmp(arr[1], "-a") == 0)
            lsa(arr[2]);
        else
            lsa(arr[1]);
    }
}