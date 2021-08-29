
#include <rm.h>
#include <ls.h>
static int rmStatic(const char *pathname, const struct stat *sbuf, int type, struct FTW *ftwb)
{
    if(remove(pathname) < 0)
    {
        perror("Could not remove");
        return -1;
    }
    return 0;
}

void rm(const char * path)
{
    char answer[10];
    int counter= 0;
    struct stat sb;

    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
    {
       counter=ls(path,0);
    }
    if(counter>0){
        printf("You are trying to delete a non-empty directory. Are you sure? y or n\n");
        if (fgets(answer, sizeof answer, stdin) == NULL) {
            fprintf(stderr, "Error");
            return;
            
        }
        else if (strcmp(answer,'y')==0){
            if (nftw(path, rmStatic ,10, FTW_DEPTH|FTW_MOUNT|FTW_PHYS) < 0)
            {
                perror("Error");
                return;
            }
        }
        else {
            printf("Action cancelled");
            return;
        }
        
    }
    else{
    if (nftw(path, rmStatic ,10, FTW_DEPTH|FTW_MOUNT|FTW_PHYS) < 0)
    {
        perror("Error");
        return;
    }
    }

}