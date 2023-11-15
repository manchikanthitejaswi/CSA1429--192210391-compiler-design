#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0, inWord = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open the file.");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        charCount++;

        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (inWord) {
                inWord = 0;
                wordCount++;
            }

            if (ch == '\n') {
                lineCount++;
            }
        } else {
            inWord = 1;
        }
    }

    if (inWord) {
        wordCount++;
    }

    fclose(file);

    printf("Character count: %d\n", charCount);
    printf("Word count: %d\n", wordCount);
    printf("Line count: %d\n", lineCount);

    return 0;
}
