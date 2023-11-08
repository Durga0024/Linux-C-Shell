#include "header.h"
#include "functions.h"
long long int mi;
char *his = "";
void delprocess(int id)
{
    int f = 0;
    if (id != -1)
    {
        for (int i = 1; i <= jc; i++)
        {
            if (ja[i].pid == id)
            {
                f = 1;
                for (int j = i; j < jc; j++)
                {
                    ja[j] = ja[j + 1];
                }
                jc--;
            }
        }
    }
    else
    {
        jc = 0;
    }
    if (f == 0 && id != -1)
    {
        printf("Error: No such process found\n");
    }
}

void done()
{
  pid_t p;
  int status;
  p = waitpid(-1, &status, WNOHANG);
  for (int z = 1; z <= jc; z++)
  {
    if (p < 0)
    {
      perror("\nwaitpid failed\n");
    }
    const int exit = WEXITSTATUS(status);


    if (((WIFEXITED(status) && p == ja[z].pid) || (kjb == 1 && p == ja[z].pid))&& ok==0)
    {
      if (kjb == 1)
        kjb = 0;
      //printf("\n");  
      //display(sym[0]);
      fflush(stdout);
      delprocess(p);
    }
  }
  if (ok == 1)
    delprocess(-1);
}

void whileloop(char *token)
{
    char *arr[1000] = {'\0'};
    //printf("%s\n",path);
    while (token != NULL)
    {
        int input = 0, output = 0, pie = 0, b = 0;
        k = 0;
        //printf("1==%d\n",k);
        int space = 0;
        char *sep = token;

        for (int i = 0; (x = strsep(&sep, " ")) != NULL; i++)
        {
            if (strcmp(x, "|") == 0)
            {
                pie++;
            }
            if (strcmp(x, ">") == 0)
            {
                output = 1;
            }
            else if (strcmp(x, ">>") == 0)
            {
                output = 2;
            }
            else if (strcmp(x, "<") == 0)
            {
                input = 1;
            }
            else if (strcmp(x, "&") == 0)
            {
                b = 1;
                //jc++;
            }
            if (strlen(x) != 0 && strcmp(x, ">") != 0 && strcmp(x, ">>") != 0 && strcmp(x, "<") != 0)
            {
                arr[i] = x;
                //printf("%d-%s\n",i,arr[i]);
                k++;
            }
            else
            {
                i--;
            }
        }
        
        int original;
        if (output == 1)
        {
            //printf("%d\n", original);
            //printf("1\n");
            k = k - 1;
            int fd = open(arr[k], O_WRONLY | O_CREAT, 0644);
            dup2(STDOUT_FILENO, original);
            //printf("%d\n", original);

            if (dup2(fd, STDOUT_FILENO) < 0)
            {
                perror("error");
                exit(1);
            }
            close(fd);
        }
        if (output == 2)
        {
            //printf("output2\n");
            k = k - 1;
            int fd = open(arr[k], O_APPEND | O_WRONLY | O_CREAT, 0644);
            dup2(STDOUT_FILENO, original);
            if (dup2(fd, STDOUT_FILENO) < 0)
            {
                perror("error");
                exit(1);
            }
            close(fd);
        }
        if (!pie)
        {
            pie++;
        }
        if (b == 1)
        {
            background(arr,k);
            //break;
        }
        else if (strcmp(arr[0], "cd") == 0)
        {
            changedir(arr[1], sym[0], k, cdpwd[0], sy[0]);
            // dup2(original, STDOUT_FILENO);
        }
        else if (strcmp(arr[0], "pwd") == 0)
        {
            pwd();
            cdpwd[0] = getcwd(s, 100);
            // dup2(original, STDOUT_FILENO);
        }
        else if (strcmp(arr[0], "echo") == 0)
        {
            echo(arr, k);
            // dup2(original, STDOUT_FILENO);
        }
        else if (strcmp(arr[0], "exit") == 0)
        {
            exit(0);
        }
        else if (strcmp(arr[0], "history") == 0)
        {
            if (k == 1)
            {
                //printf("hello1");
                history(path);
                // dup2(original, STDOUT_FILENO);
            }
            else
            {
                //printf("hello2");
                history_num(arr[1], path);
                // dup2(original, STDOUT_FILENO);
            }
            //printf("\n");
        }
        else if (strcmp(arr[0], "pinfo") == 0)
        {
            pinfo(arr, k);
            // dup2(original, STDOUT_FILENO);
            break;
        }
        else if (strcmp(arr[0], "repeat") == 0)
        {
            repeat(arr, k);
            // dup2(original, STDOUT_FILENO);
        }
        else if (strcmp(arr[0], "jobs") == 0)
        {
            //printf("hi\n");
            jobs(arr, k);
            // dup2(original, STDOUT_FILENO);
            break;
        }
        else if (strcmp(arr[0], "sig") == 0)
        {
            sigjobs(arr, k);
            // dup2(original, STDOUT_FILENO);
        }
        else if (strcmp(arr[0], "bg") == 0)
        {
            bg(arr);
            // dup2(original, STDOUT_FILENO);
        }
        else if (strcmp(arr[0], "fg") == 0)
        {
            fg(arr);
            // dup2(original, STDOUT_FILENO);
        }
        else if (strcmp(arr[0], "ls") == 0)
        {
            ls(sym[0], arr, k);
            // dup2(original, STDOUT_FILENO);
        }
        else
        {
            //printf("f\n");
            foreground(arr, k);
            //dup2(original, STDOUT_FILENO);
            //printf("broh im there\n");
        }
        //printf("last %d\n",original);
        dup2(original, STDOUT_FILENO);
        token = strtok(NULL, ";");
        his = buf;
    }
}
void display(char *sim)
{
    username = getenv("USER");
    struct utsname detect;
    uname(&detect);
    //char s[100];
    sy[0] = getcwd(s, 100);
    //printf("before:%s\n",sy[0]);
    cdpwd[0] = sy[0];
    //printf("\n");
    printf("\033[1;32m");
    //printf("\033[4;31m");
    if (strcmp(sim, sy[0]) == 0)
    {
        printf("<%s@%s:~>", username, detect.sysname);
    }
    else
    {
        printf("<%s@%s:%s>", username, detect.sysname, sy[0]);
    }
    printf("\033[0m");
    buf = readline(" ");
    if (buf == NULL)
    {
        printf("\n");
        exit(0);
    }

    if (strlen(buf) != 0)
    {
        //printf("i am here");
        add_history(buf);
    }
    token = strtok(buf, ";");
    int fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0)
    {
        perror("");
        exit(0);
    }
    if (strcmp(his, buf) != 0)
    {
        int sz = write(fd, buf, strlen(buf));
        sz = write(fd, "\n", 1);
        //count++;
    }
    close(fd);
    whileloop(token);
}
void cc(int sig)
{
    pid_t p = getpid();
    if (p != mi)
    {
        return;
    }
    if (p == mi && cf.pid == -1)
    {
        printf("\n");
        display(sym[0]);
        fflush(stdout);
    }
    if (cf.pid != -1)
    {
        kill(cf.pid, SIGINT);
    }
}
void cz(int sig)
{
    pid_t p = getpid();
    if (p != mi)
        return;
    if (cf.pid != -1)
    {
        kill(cf.pid, SIGTTIN);
        kill(cf.pid, SIGTSTP);
        jc++;
        ja[jc].pid = cf.pid;
        strcpy(ja[jc].nme, cf.nme);
        return;
    }
    signal(SIGTSTP, cz);
    if (p == mi)
    {
        printf("\n");
        display(sym[0]);
        fflush(stdout);
    }
    //printf("\n");
    return;
}
void ctd(int siq)
{
    exit(0);
}

int main()
{
    clear();
    char s1[100], c;
    // jobpath = malloc(strlen(sym[0])+ 1);
    sym[0] = getcwd(s1, 100);
    //strcpy(jobpath,sym[0]);
    //char *re=malloc(sizeof(long int)+1);
    //char *reout=malloc(sizeof(long int)+1);
    path = malloc(strlen(sym[0]) + strlen("/history.txt") + 1);
    strcpy(path, sym[0]);
    strcat(path, "/history.txt");
    char name[100];
    mi = getpid();
    jc = 0;

    //FILE *file;
    // char *his = "";
    //int count = 0;
    while (1)
    {
        cf.pid = -1;
        signal(SIGCHLD,done);
        signal(SIGINT, cc);
        signal(SIGTSTP, cz);
        signal(SIGQUIT, ctd);
        //printf("\n");
        display(sym[0]);
    }
}
