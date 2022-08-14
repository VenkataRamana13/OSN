#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

extern int errno; 

int main(int argc, char **argv){
    
    int fd1, fd2, fd3; 
    char buffer[80]; 
    char msg[80]; 
    char new_file[50] = "1_"; 
    
    strcat(new_file, argv[1]); 
    
    fd2 = creat(new_file, 00700); 
    fd1 = open(argv[1], O_RDONLY); 
    
    if(fd1 == -1){
        perror("r1"); 
        exit(1); 
    }
     
    if(fd2 == -1){
        perror("r1"); 
        exit(1); 
    }
     
    read(fd1, buffer, sizeof(buffer));
     
    int i = 0; 
    for(i = 0; buffer[i] != '\0'; i++); 
    for(int j = 0; j < i; j++){
        msg[j] = buffer[i - j - 1]; 
    }
    
    write(fd2, msg, sizeof(msg)); 
     
    return 0;
}
