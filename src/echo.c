#include <echo.h>

int echo(char **args, int argCount){

    for(int i=1;i<argCount;++i){
        printf("%s ",args[i]);

    }
    return 0;
}