#include<stdio.h>

int main(){
    char name[80];
    printf("Enter your name :\n");
    scanf("%79s",name);
    printf("Hello %s",name);
    return 0;
}