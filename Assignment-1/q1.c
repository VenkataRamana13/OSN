#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

extern int errno; 

int main(int argc, char **argv){
    
    int fd1, fd2;       //file descriptor ints
    char *dirname = "Assignment"; 
    mkdir(dirname, 0777); 
    char new_file[100] = "Assignment/1_";      //output file name to be appended
    
    strcat(new_file, argv[1]);      //appended to input file name
    
    fd2 = creat(new_file, 00700);   //created output file
    fd1 = open(argv[1], O_RDONLY);  //read input file
    
    if(fd1 == -1){          //error handling
        perror("r1"); 
        exit(1); 
    }
     
    if(fd2 == -1){
        perror("r1"); 
        exit(1); 
    }
     
    int file_size = lseek(fd1, 0, SEEK_END);   //finding the file size of input file 
    
    int byte_size = file_size / 500;        //a percentage of file to be processed 
    int bytes_read; 
    if(byte_size == 0)
        bytes_read = 1; 
    else
        bytes_read = pow(2, (int)(log((double)(byte_size))/log(2.0)));  
    //chunk size taken to be closest power of 2 to the percentage
    
    char *Read, *Write; 
    Read = (char *)malloc(bytes_read);  //char array to store input chunk size 
    Write = (char *)malloc(bytes_read); //char array to store output chunk size
    
    int start = ((file_size - 1) / bytes_read) * bytes_read; //set as starting location of last chunk 
    int length = file_size - start;     //size of chunk to be read
    lseek(fd1, start, SEEK_SET);     

    while(1){
        read(fd1, Read, length);    //read length bytes and store in Read 
        for(int i = 0, j = length - 1; i < length; i++, j--){
            Write[i] = Read[j]; 
        }           //reverse contents of Read and store in Write
        Write[length] = '\0';       
        write(fd2, Write, length);      //write to destination file
        if(lseek(fd1, 0, SEEK_CUR) - bytes_read - length < 0)
            break;              //checking for leftover chunks to read 
        lseek(fd1, -bytes_read - length, SEEK_CUR); 
        length = bytes_read;    //move offset to start of previous chunk 
    }
    
    return 0;
}
