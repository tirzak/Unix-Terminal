#include <cat.h>
#include <echo.h>
#include <copy.h>
#include <limits.h>
#include <colors.h>
#include <ls.h>
#include <cd.h>

int argCount=0;

char * parse_args(const char* str, char **args);
void printUsage();
void printCurrentDir();




int main (int argc, char ** argv){
char buffer[20];
char str[20];
char* ch;
char c;

char *argVals[4]={'\0'};
const char * quit = "quit";
const char * echoV="echo";
const char * copy="cp";
const char * catV="cat";
const char * lsV="ls";
const char * cdV="cd";

printUsage();
printCurrentDir();

 
while (fgets(buffer, 20, stdin)!=NULL) {
        
        strcpy(str,buffer);
        
        ch = str;
        while (*ch != '\n' &&  *ch != '\0') {
            ++ch;
        }
        if (*ch) {
            *ch = '\0';
        } else {         
            while ((c = getchar()) != '\n' && c != EOF)
                continue;
        }
        if(strcmp(str,quit)==0){
                break;
        }
        else if(strstr(str, catV) != NULL) {
                 char * f=parse_args(str,argVals);
                if(argCount==2){
                        cat(argVals[1]);
                }
                else{
                        printf("cat expects only one argument\n");
                }
                 
                 free(f);
        }
        else if(strstr(str, echoV) != NULL) {
                char * f=parse_args(str,argVals);
               
                echo(argVals,argCount);
               
                free(f);
               
        }
        else if(strstr(str, copy) != NULL){
                char * f=parse_args(str,argVals);
                if(argCount==3){
                cp(argVals[1],argVals[2]); 
                }
                else{
                        printf("To copy, please enter only two arguments\n");
                }
                free(f);
                
        }
        else if(strstr(str, lsV) != NULL){
                char * f=parse_args(str,argVals);
                if(argCount==2){
                ls(argVals[1]); 
                }
                else{
                        printf("ls expects only one argument\n");
                }
                free(f);

        }
        else if(strstr(str, cdV) != NULL){
                char * f=parse_args(str,argVals);
                if(argCount==2){
                cd(argVals[1]); 
                }
                else{
                        printf("cd expects only one argument\n");
                }
                free(f);

        }
        else{
               printUsage();
        }
        printCurrentDir();
        

    
}
return 0;

}

char * parse_args(const char* str, char **args){

char *token, *strs, *tofree;
tofree = strs = strdup(str);
argCount=0;
while ((token = strsep(&strs, " "))) {
        
        args[argCount]=token;
        argCount++;
}
return tofree;
}

void printUsage(){
         printf("Usage:\n"
                "1. echo string (To echo something)\n"
                "2. cp src dest (To copy file)\n"
                "3. cat file (To print contents of file)\n"
                "4. ls path (To list files and dirs in a path)\n"
                "5. cd path (To change current working dir)\n"
                "6. quit (To exit)");
}


void printCurrentDir(){
char cwd[PATH_MAX];

if (getcwd(cwd, sizeof(cwd)) == NULL) {

        perror("getcwd() error");
        


} 
printf("\n%sterminal: %s%s%s> ",BGRN,BBLU,cwd,WHT);   

}
