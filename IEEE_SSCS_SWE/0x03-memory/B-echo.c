#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    if (argc ==1 ){  
        printf("Silence. Nothing came through.\n")  ;
    
    }
    else{
        for(int i=1;i<argc ;i++) {   //start from the second element 
            printf("%s \n"  ,argv[i])  ;
        }
    }
    return 0;
}
