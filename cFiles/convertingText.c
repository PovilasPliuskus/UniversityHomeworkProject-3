#include<stdio.h>
#include"../headerFiles/convertingText.h"

#define limit 255

void takingCharacters(char *previousCharacter, char *goingCharacter, FILE inputFile[], int *limitPointer);
void printingCharacter(char previousCharacter, char goingCharacter, FILE outputFile[], int *number);
void Cycle(FILE inputFile[], FILE outputFile[]);

void Converting(char inputFileName[], char outputFileName[])
{
    FILE *inputFile;
    inputFile = fopen(inputFileName, "r");

    FILE *outputFile;
    outputFile = fopen(outputFileName, "w+");

    Cycle(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);
    return;
}

void Cycle(FILE inputFile[], FILE outputFile[])
{
    char previousCharacter = ' ', goingCharacter;
    int numberOfTheSameCharacter = 1;
    int limitPointer = 0;

    while (feof(inputFile) == 0) {
        takingCharacters(&previousCharacter, &goingCharacter, inputFile, &limitPointer);
        if (previousCharacter == ' ' && limitPointer != 1) {
            fprintf(outputFile, " ");
        }
        else {
            printingCharacter(previousCharacter, goingCharacter, outputFile, &numberOfTheSameCharacter);
        }

        if (goingCharacter == '\n') {
            fprintf(outputFile, "%c", '\n');
            Cycle(inputFile, outputFile);
        }

        if (limitPointer == limit) {
            fscanf(inputFile, "%*[^\n]\n");
            fprintf(outputFile, "%c%c%d", goingCharacter, '$', numberOfTheSameCharacter);
            fprintf(outputFile, "%c", '\n');
            Cycle(inputFile, outputFile);
        }
    }
}

void takingCharacters(char *previousCharacter, char *goingCharacter, FILE inputFile[], int *limitPointer)
{
    if (*limitPointer == 0) {
        *goingCharacter = fgetc(inputFile);
    }
    else {
        *previousCharacter = *goingCharacter;
        *goingCharacter = fgetc(inputFile);
    }
    (*limitPointer)++;
}

void printingCharacter(char previousCharacter, char goingCharacter, FILE outputFile[], int *number)
{
    if (previousCharacter == goingCharacter && goingCharacter != ' ') {
        (*number)++;
    }
    else if (previousCharacter != ' ') {
        fprintf(outputFile, "%c", previousCharacter);
        if (*(number) > 1) {
            fprintf(outputFile, "%c%d", '$', *number);
        }
        (*number) = 1;
    }
}