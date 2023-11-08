#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <grp.h>
#include <time.h>
#include <sys/utsname.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/history.h>
#include <readline/readline.h>
#define clear() printf("\033[H\033[J")
char *username;
struct utsname detect;
char *buf;
int k;
char *x;
//int input = 0, output = 0, pie = 0;
char *token;
char s[10000];
char *sy[10000];
char *cdpwd[10000];
char *sym[10000];
char *path;
//char *jobpath;
int jc;
typedef struct jbs
{
    char nme[10000];
    pid_t pid;
} jb;
struct jbs ja[10000];
struct jbs cf;
int kjb ;
int ok;
//char** s1[100];
//char* sym[];
