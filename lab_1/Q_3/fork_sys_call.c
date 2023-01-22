#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char * argv[]){
    int id=fork();
    int childid1,childid2,parentid;
    if(id==0){
        childid1=id;
        printf("Child 1 id : %d\n",id);
        
    }else{
        int id2=fork();
        if(id2!=0){
            parentid=id;
        }
        else{
            childid2=id;
        }

        
    }
    printf("Parent Id: %d, Child 1 : %d, Child 2 : %d\n",parentid,childid1,childid2);
    
    // if(id!=0){
    //     int id2=fork();
    //     printf("Hello world %d\n",id2);
        
    // }
    // printf("Hello World %d\n",id);
    // if(id==0){
    //     printf("Hello from child process!\n");
    // }
    // else{
    //     fork();
    //     printf("Hello from parent process!\n");
    // }
    return 0;
}