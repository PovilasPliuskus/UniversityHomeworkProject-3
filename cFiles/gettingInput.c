#include<stdio.h>
#include<stdlib.h>
#include"../headerFiles/gettingInput.h"

char *InputFile()
{
    int inputFileNameLength = 0;
    char *inputFileName = (char *)malloc(inputFileNameLength);
    printf("Iveskite duomenu failo pavadinima (pvz.: 'duomenys.txt'): ");
    char tempChar;
    tempChar = getchar();
    while(tempChar != '\n') {
        inputFileNameLength++;
        inputFileName = (char *)realloc(inputFileName, sizeof(char) * inputFileNameLength);
        *(inputFileName + inputFileNameLength - 1) = tempChar;
        tempChar = getchar();
    }
    inputFileName = (char *)realloc(inputFileName, (sizeof(char) * inputFileNameLength) + 1);
    *(inputFileName + inputFileNameLength) = '\0';
    return inputFileName;
}

char *OutputFile()
{
    int outputFileNameLength = 0;
    char *outputFileName = (char *)malloc(outputFileNameLength);
    printf("Iveskite rezultatu failo pavadinima (pvz.: 'rezultatas.txt'): ");
    char tempChar;
    tempChar = getchar();
    while (tempChar != '\n') {
        outputFileNameLength++;
        outputFileName = (char *)realloc(outputFileName, sizeof(char) * outputFileNameLength);
        *(outputFileName + outputFileNameLength - 1) = tempChar;
        tempChar = getchar();
    }
    outputFileName = (char *)realloc(outputFileName, (sizeof(char) * outputFileNameLength) + 1);
    *(outputFileName + outputFileNameLength) = '\0';
    return outputFileName;
}