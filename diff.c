//create an array of char * that hold the string in each line
//as you go through the other file, you make sure that each line is the exact same
//if not you print out that line
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//const char* string[2][8] = {{"01000001"} , {01000011}}

int main(int argc, const char *argv[]){
    //char linesFirst[5][40]; //array of character pointers
    char linesFirst[5][40];
    int lineCounter = 0;
    char c;
    FILE *fin = fopen(argv[1], "r");
    do {
        int i = 0;
        while(((c = getc(fin)) != EOF) && c != '\n'){ //while file is not over and not a new line
            linesFirst[lineCounter][i++] = c;
        }   
        if(i > 0){
            if(c == '\n'){
            linesFirst[lineCounter][i] = '\n';
            ++lineCounter;
            } 
        }
      
    } while (c != EOF);
    for(int i = 0; i<lineCounter; ++i){
        printf("%s\n" , linesFirst[i]);
    }
    fclose(fin);
    return 0;
}