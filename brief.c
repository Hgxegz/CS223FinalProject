//create an array of char * that hold the string in each line
//as you go through the other file, you make sure that each line is the exact same
//if not you print out that line
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define LINE 40


void getValues(char fromArray[][LINE], FILE *fin); //function to get values from first file into a two dimensional array
bool iterateSecond(char fromArray[][LINE], FILE *fin2); //function to go throught second file and make sure the lines are there 


int main(int argc, const char *argv[]){
    FILE  *original = fopen(argv[1], "r");
    FILE  *comparer = fopen(argv[2], "r");
    char  linesFirst[5][LINE];
    bool result;
    getValues(linesFirst, original); //puts each line from the first file into an array of strings
    printf("Got lines into array");
    result = iterateSecond(linesFirst, comparer);
    printf("Checked each line successfully\n");
    if(!result){
        printf("The files are not the same");
    } else {
        printf("They match");
    }

    /*
    //variables for the second functi //opens the second file
    char *line_buf = NULL; //creates the buffer for the line we need to check
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;
    bool final;
    
    //COMPARING LINES FROM FILE 2 TO FIRST FILE
    line_size = getline(&line_buf, &line_buf_size, comparer);
    while(line_size >= 0){
        if(!isMatching(linesFirst, line_buf)){
            final = false;
        }
    }
    final = true;
    if(final == false){
        printf("Files do not match.");
    } else {
        printf("they are the same");
    }    */
    return 0;
}



void getValues(char fromArray[][LINE], FILE *fin){ //function to get values from first file into a two dimensional array
    int   lineCounter = 0, lineCounter2 = 0;
    char  c;
    do {
        int i = 0;
        while(((c = getc(fin)) != EOF) && c != '\n'){ //while file is not over and not a new line
            fromArray[lineCounter][i++] = c;
        }   
        if(i > 0){
            if(c == '\n'){
            fromArray[lineCounter][i] = '\0';
            ++lineCounter;
            }  
        }
    } while (c != EOF);
    fclose(fin); 
}

bool iterateSecond(char fromArray[][LINE], FILE *fin2){ //returns true if all lines match
    char *line_buf = NULL; //creates the buffer for the line we need to check
    size_t line_buf_size = 0;
    int line_count = 0;
    int check = 0;

    while(getline(&line_buf, &line_buf_size, fin2) != EOF){ //reads new lines until the end of the file
        for(int i = 0; i<5; ++i){
            if(strcmp(fromArray[i], line_buf) == 0){
                ++check;
            }
        }
    }
    if(check >= 5)
        return true;
    else 
        return false;
       
}