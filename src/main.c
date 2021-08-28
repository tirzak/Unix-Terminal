#include <cat.h>
#include <echo.h>
#include <copy.h>

char * parse_args(const char* str, char **args);

int main (int argc, char ** argv){
char buffer[20];
char str[20];
char* ch;
char c;
int i;
char *argVals[4]={'\0'};
const char * quit = "quit";
const char * echoV="echo";
const char * copy="copy";
const char * catV="cat";


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
                 cat(argVals[1]);
                 free(f);
        }
        else if(strstr(str, echoV) != NULL) {
                char * f=parse_args(str,argVals);
                echo(argVals[1]);
                free(f);
               
        }
        else {
                char * f=parse_args(str,argVals);
                cp(argVals[1],argVals[2]); 
                free(f);
                
        }
        

    
}

}

char * parse_args(const char* str, char **args){
const char * ans="";
char *token, *strs, *tofree;
tofree = strs = strdup(str);
int i=0;
while ((token = strsep(&strs, " "))) {
        
        args[i]=token;
        i++;
}
return tofree;
}



