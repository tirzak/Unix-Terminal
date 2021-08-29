#include <cd.h>
void cd (const char *newdir){
    if (chdir(newdir) != 0)
        perror("chdir() to /tmp failed");
}