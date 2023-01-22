#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<time.h>
#include <dirent.h>

int main(int argc, char *argv[]){
    int id=fork();
    struct dirent *de;//pointer to the directory entry
    DIR *dr=opendir(".");
    int child1,parent,child2;
    time_t tm;
    if(id==0){
        child1=getpid();
        printf("Child 1, ID : %d\n",child1);
        time(&tm);
        printf("Current Date/Time = %s", ctime(&tm));
        // sleep(1);
    }
    // int n;
    // if(id==0){
    //     n=1;
    // }
    // else{
    //     n=6;
    // }
    // if(id!=0){
    //     wait();//only wait in main process. wait allows child process execution before parent
    // }

    // for(int i=n;i<n+5;i++){
    //     printf("%d ",i);
    //     // fflush(stdout);
    // }
    // if(id==0){
    //     printf("\n");
    // }
    // printf("Current ID : %d, parent ID : %d\n",getpid(),getppid());
    if(id!=0){
        // wait(NULL);
        parent=getpid();
        int second_id=fork();
        if (second_id==0){
            child2=getpid();
            printf("Child 2 ID : %d\n",child2);
            if(dr==NULL){
                printf("Couldn't open current directory");
                return 1;
            }
            while((de=readdir(dr))!=NULL){
                printf("%s\n",de->d_name);
            }
            closedir(dr);


        }else{
            printf("Parent ID : %d\n",getpid());
            // wait(NULL);
        }



    }
    
    return 0;
}