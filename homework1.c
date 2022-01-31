#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Table 
{
    char *word;
    int count;
};


void display_table(struct Table table[], int n)
{
    int i = 0;
    for (i = 0; i < n; i++) {
        printf("%s: \t %d", table[i].word, table[i].count);
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    //initializing the variables//
    int n = argc - 1;
    struct Table init_table[n];
    char * line = NULL;
    size_t len = 0;
    ssize_t lineSize;
    int i;
    for (i = 1; i < argc; i++)
    
    {
        init_table[i - 1].word = argv[i];
        init_table[i - 1].count = 0;
    }

    display_table(init_table, n);
   
    while ((lineSize = getline(&line, &len, stdin)) >= 1) 

    {
        //printf("Retrieved line of length %zu:\n", read);//
        printf("%s", line);
        char *word=malloc(1000 * sizeof(char));
        int k = 0;

        // Iterate over each character in line//
        while (k < lineSize){

            char charSelected = line[k];
            
            // Conditions when to check for word//
            if (charSelected == ' ' || charSelected == '\n' || charSelected == '.') 
            
            {
                /* Iterate over init_table and determine if the word matches init_table.word*/
                for (i = 0; i < n; i++){

                    if (strcmp(init_table[i].word, word) == 0) {
                        init_table[i].count++;
                    }
                }
                word[0] = '\0';
            }
            else 
            {
                // Concatinating characters
                strncat(word, &charSelected, 1);
            }
            
            k++;
        }
    }
    display_table(init_table, n);

    
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}