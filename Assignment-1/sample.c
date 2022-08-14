#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
    int fd; 
    char buffer[80]; 
    char msg[50]; 
    fd = open("check.txt", O_RDWR); 
    printf("fd = %d", fd); 
    if(fd != -1){
        printf("\ncheck.txt opened with read write access\n"); 
        lseek(fd, 0, SEEK_SET); 
        write(fd, msg, sizeof(msg)); 
        read(fd, buffer, sizeof(msg)); 
        printf("\n%s was written to my file\n", buffer); 
        close(fd); 
    }
    return 0; 
}
