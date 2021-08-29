#include <ls.h>
#include <colors.h>
void ls(const char * dirName){
    DIR *directory;

    struct dirent *dirStruct;

    directory=opendir(dirName);

    if(directory){
        while ((dirStruct=readdir(directory))!=NULL)
        {
           
            if(dirStruct-> d_type != DT_DIR) {
            printf("%s\n", dirStruct->d_name);
            }
            else if(dirStruct -> d_type == DT_DIR && strcmp(dirStruct->d_name,".")!=0 && strcmp(dirStruct->d_name,"..")!=0 ) 
            {
                printf("%s%s%s\n",BLU, dirStruct->d_name,WHT); 
     
            }
        }
        closedir(directory);
        

    }
}