#include <cat.h>
#include <echo.h>

int main (int argc, char ** argv){
char buffer[20];
char str[20];
char* ch;
char c;
int i;


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
                cat(str);
        }
        else if(strstr(str, echoV) != NULL) {
                echo(str);
        }
        

    
}

}



