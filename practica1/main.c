#include<stdio.h>
#include<stdlib.h>
#include "pila.h"


int main(int argc, char*argv[]){

    char *regularEx = argv[1];
    char *cadPost;
    //printf("%s",regularEx);

    cadPost = inapos(regularEx);

    printf("La cadena postfija es : %s\n",cadPost);


    return 0;
}
