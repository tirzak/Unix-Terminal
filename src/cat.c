
#include <cat.h>

void cat(char *s){

FILE* filePointer;
int bufferLength = 4096;
char buffer[bufferLength];

filePointer = fopen(s, "r");

while(fgets(buffer, bufferLength, filePointer)) {
    printf("%s\n", buffer);
}

fclose(filePointer);
}