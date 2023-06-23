#include <stdio.h>
#include <string.h>

int countOccurrences(char *line, char *phrase) {
    int count = 0;
    char *substring = strstr(line, phrase);
    while (substring != NULL) {
        count++;
        substring = strstr(substring + 1, phrase);
    }
    return count;
}

void markPhrase(char *line, char *phrase) {
    int i;
    for (i = 0; i < strlen(line); i++) {
        if (line[i] == phrase[0] && line[i+strlen(phrase)] != phrase[strlen(phrase)]){
            printf("'%s'", phrase);
            i += strlen(phrase);
        } else {
            printf("%c", line[i]);
        }
    }
}

int main() {
    char phrase[256], fileName[256];
    int count = 0, i;
    FILE *fp;

    printf("Enter the phrase you want to search for: ");
    scanf("%s", phrase);

    printf("Enter the file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    char line[512];
    int lineNumber = 1;
    while (fgets(line, sizeof(line), fp)) {
        count = countOccurrences(line, phrase);
        if (count > 0) {
            printf("Line %d: ", lineNumber);
            markPhrase(line, phrase);
            printf(" (occurrences: %d)\n", count);
        }
        count = 0;
        lineNumber++;
    }

    if(count != 0)
    {
        printf("The phrase '%s' was found in the file.\n", phrase);
    }
    fclose(fp);
    return 0;
}