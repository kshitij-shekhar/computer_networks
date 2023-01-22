#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

int main(int argc, char **argv){
    /* Pointer to the source file and output file */
    FILE *src,*out_src;
    /* File is read one character at a time*/
    char c,ch;
    while((ch=getopt(argc,argv,"i:o:"))!=EOF){
        switch(ch){
            case 'i':
                src = fopen (optarg, "r");
                break;
            case 'o':
                out_src=fopen(optarg,"w");
                break;

            default:
                src = fopen("sample.txt","r");
                break;
        }
    }
    // argc-=optind;
    // argv+=optind;
    /* Opening source file in read mode*/
    // src = fopen ("sample.txt", "r");
    if( src == NULL ){
        printf("File not found. Exiting.\n");
        exit(EXIT_FAILURE);
    }
    /* Read src until end-of-file char is encountered */
    while( (c = fgetc(src)) != EOF ){
        printf("%c", c);
        fprintf(out_src,"%c",c);
    }
    
    fclose(src);
    return 0;
}