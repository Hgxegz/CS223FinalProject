//create an array of char * that hold the string in each line
//as you go through the other file, you make sure that each line is the exact same
//if not you print out that line
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define LINE 40

void isMatching(char fromArray[][LINE], char *fromFile);


int main(int argc, const char *argv[]){
    //variables for the first function
    FILE  *original = fopen(argv[1], "r");
    char  *check;
    char  *check2 = "This is an important";
    char  linesFirst[5][LINE];
    int   lineCounter = 0, lineCounter2 = 0;
    char  c;
    
    //THIS IS GETTING THE WORDS INTO AN ARRAY FROM FILE 1
    do {
        int i = 0;
        while(((c = getc(original)) != EOF) && c != '\n'){ //while file is not over and not a new line
            linesFirst[lineCounter][i++] = c;
        }   
        if(i > 0){
            if(c == '\n'){
            linesFirst[lineCounter][i] = '\0';
            ++lineCounter;
            }  
        }
    } while (c != EOF);
    fclose(original);
    

   /* //variables for the second function
    FILE  *comparer = fopen(argv[2], "r");
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;
    
    //COMPARING LINES FROM FILE 2 TO FIRST FILE
    line_size = getline(&line_buf, &line_buf_size, comparer);
    while(line_size >= 0){
        //check = linesFirst[line_count];
        if(strcmp(linesFirst[line_count], line_buf) != 0){
            printf("Line %d does not match each other ")
        }
    }
    */
   isMatching(linesFirst, check2);
    /*
    int proto = 0;
    check = linesFirst[0];
    proto = strcmp(check, check2);
    printf("check returned %d\n" , proto);
    printf("%s ---> %s" ,check, check2); */
    
    return 0;
}


void isMatching(char fromArray[][LINE], char *fromFile){
    for(int i = 0; i < 5; ++i){
        if(strcmp(fromArray[i], fromFile) == 0){
            printf("line %d has match\n", i+1);
            printf("%s", fromArray[i]);
        } 
    }
}