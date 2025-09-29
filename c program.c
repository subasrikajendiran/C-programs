
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char filename[100], ch;
    int lines = 0, words = 0, characters = 0;
    int inWord = 0; // Flag to detect words

    // Ask user for file name
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open file in read mode
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read file character by character
    while ((ch = fgetc(fp)) != EOF) {
        characters++;

        if (ch == '\n')
            lines++;

        // Check for word
        if (isspace(ch)) {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }

    fclose(fp);

    printf("\nFile: %s\n", filename);
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}