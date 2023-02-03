// LSP - 2213783, pastas - povilas.pliuskus@mif.stud.vu.lt
// uzduotis - 3.7

//4.8 prognoze
#include<stdio.h>
#include<stdlib.h>
#include"../headerFiles/gettingInput.h"
#include"../headerFiles/inputValidation.h"
#include"../headerFiles/convertingText.h"

int main()
{
    char *inputFile;
    char *outputFile;

    do {
        inputFile = InputFile();
    } while (InputFileValidation(inputFile) == 0);

    do {
        outputFile = OutputFile();
    } while (OutputFileValidation(outputFile) == 0);

    Converting(inputFile, outputFile);

    free(inputFile);
    inputFile = NULL;

    free(outputFile);
    outputFile = NULL;

    printf("Programa sekmingai ivykdyta\n");

    return 0;
}