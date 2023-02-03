#include<stdio.h>
#include"../headerFiles/inputValidation.h"

int InputFileValidation(char inputFileName[])
{
    FILE *inputFile;
    inputFile = fopen(inputFileName, "r");

    if (inputFile != NULL) {
        fclose(inputFile);
        return 1;
    }
    else {
        printf("Nepavyko atidaryti duomenu failo\n");
        return 0;
    }
}

int OutputFileValidation(char outputFileName[])
{
    FILE *outputFile;
    outputFile = fopen(outputFileName, "w+");

    if (outputFile != NULL) {
        fclose(outputFile);
        return 1;
    }
    else {
        printf("Nepavyko atidaryti rezultatu failo\n");
        return 0;
    }
}