#include <copy.h>
int cp(const char *src, const char *dest)

{
    int fd_src, fd_dest;
    char buffer[8192];

    ssize_t readN;

    char *reader;

    fd_src = open(src, O_RDONLY);
    if (fd_src < 0){
        printf("Error opening file");
        return -1;
    }

    fd_dest = open(dest, O_WRONLY | O_CREAT | O_EXCL, 0666);
      if (fd_src < 0){
        printf("Copy Error");
        close(fd_src);
        return -1;
    }

    while (readN = read(fd_src, buffer, sizeof buffer), readN >0){
        reader=buffer;
        ssize_t writeN;

        while (readN>0)
        {
            writeN=write(fd_dest, reader, readN);

            if(writeN>=0){
                readN -= writeN;
                reader += writeN;
            }

            else if (errno != EINTR){
                close(fd_src);
                printf("Error while copying");
                close(fd_dest);
                return -1;
            }
        }

        if (readN==0){
            if(close(fd_dest)<0){
                fd_dest=-1;
                close(fd_src);
                return -1;
            }
            close(fd_src);
            return 0;
        }
        

    }

}