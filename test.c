#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>

int main(){
    int fd; 
    char buffer[100]; 
    char msg[50] = "hello syscall programming"; 
    fd = open("check.txt", O_CREAT | O_RDWR, 00700); 
    if(fd != -1){
        printf("\ncheck.txt opened with read write access\n"); 
        write(fd, msg, sizeof(msg)); 
        lseek(fd, 5, SEEK_SET); 
        read(fd, buffer, sizeof(msg)); 
        printf("\n %s was written to my file\n", buffer); 
        close(fd); 
    }
    return 0; 
}
