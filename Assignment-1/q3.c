#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){ 

    struct stat sb; 
    printf("Directory is created: ");
    if(stat(argv[3], &sb) == 0 && S_ISDIR(sb.st_mode))
    {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    
    //file contents reversed to be done

    printf("User has read permissions on new file: ");
    int ret = access(argv[1], R_OK); 
    if(ret == 0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    
    printf("User has write permissions on new file: ");
    ret = access(argv[1], W_OK);
    if(ret == 0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    
    printf("User has execute permissions on newfile: ");
    ret = access(argv[1], X_OK);
    if(ret == 0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    
    
}
