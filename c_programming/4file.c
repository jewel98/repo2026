#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *file;
    char line[256];

    file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Cannot open input.txt");
        return EXIT_FAILURE;
    }



    // 2. Loop through the file until fgets returns NULL (End of File)
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);


        file = fopen("output.txt", "w");

    if (file == NULL) {
        perror("Cannot open output.txt");
        return EXIT_FAILURE;
    }

    fputs("This is the first line.\n", file);
    fputs("This is the second line.\n", file);

    fclose(file);

    printf("\nTwo lines were written to output.txt.\n");


    FILE *fptr;

    // Open a file in append mode
    fptr = fopen("output.txt", "a");

    // Append some text to the file
    fprintf(fptr, "\nThis is the third line!");

    // Close the file
    fclose(fptr);

    return EXIT_SUCCESS;
}
