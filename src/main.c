#include <cat.h>
#include <echo.h>
#include <copy.h>
#include <limits.h>
#include <colors.h>
#include <ls.h>
#include <cd.h>
#include <rm.h>


int argCount=0;

char * parse_args(const char* str, char **args);
void printUsage();
void printCurrentDir();




int main (int argc, char ** argv){
char buffer[256];
char str[256];
char* ch;
char c;

char *argVals[4]={'\0'};
const char * quit = "quit";
const char * echoV="echo";
const char * copy="cp";
const char * catV="cat";
const char * lsV="ls";
const char * cdV="cd";
const char * rmV="rm";

printUsage();
printCurrentDir();

 
while (fgets(buffer, 256, stdin)!=NULL) {
        
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
        char * q=parse_args(str,argVals);
        if(strcmp(argVals[0],quit)==0){
                break;
        }
        else if(strcmp(argVals[0], catV)==0) {
                 
                if(argCount==2){
                        cat(argVals[1]);
                }
                else{
                        printf("cat expects only one argument\n");
                }
                 
                 
        }
        else if(strcmp(argVals[0], echoV)==0) {
                
               
                echo(argVals,argCount);
               
                
               
        }
        else if(strcmp(argVals[0], copy)==0){
                
                if(argCount==3){
                cp(argVals[1],argVals[2]); 
                }
                else{
                        printf("To copy, please enter only two arguments\n");
                }
                
                
        }
        else if(strcmp(argVals[0], lsV)==0){
                
                if(argCount==2){
                ls(argVals[1],1); 
                }
                else{
                        printf("ls expects only one argument\n");
                }
              
        }
        else if(strcmp(argVals[0], cdV)==0){
                
                if(argCount==2){
                cd(argVals[1]); 
                }
                else{
                        printf("cd expects only one argument\n");
                }
             

        }
        else if(strcmp(argVals[0], rmV)==0){
                
                if(argCount==2){
                rm(argVals[1]); 
                }
                else{
                        printf("rm expects only one argument\n");
                }
             

        }
        else{
               printUsage();
        }
        printCurrentDir();
        
        
        free(q);
    
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
