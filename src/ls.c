#include <ls.h>
#include <colors.h>
int ls(const char * dirName, int printVal){
    DIR *directory;
    int counter = 0;
    struct dirent *dirStruct;

   if ((directory = opendir(dirName)) == NULL) {
        perror("Error opening directory");
        return -1;
    }

    if(directory){
        while ((dirStruct=readdir(directory))!=NULL)
        {
           
            if(dirStruct-> d_type != DT_DIR) {
            if(printVal){
            printf("%s\n", dirStruct->d_name);
            }
            counter++;
            }
            else if(dirStruct -> d_type == DT_DIR && strcmp(dirStruct->d_name,".")!=0 && strcmp(dirStruct->d_name,"..")!=0 ) 
            {
                if(printVal){
                printf("%s%s%s\n",BLU, dirStruct->d_name,WHT); 
                }
                counter++;
     
            }
        }
        closedir(directory);
        
        
    }
    return counter;
}