output: uzduotis3.o gettingInput.o inputValidation.o convertingText.o
	gcc uzduotis3.o gettingInput.o inputValidation.o convertingText.o -o output.exe

uzduotis3.o: cFiles/uzduotis3.c
	gcc -c cFiles/uzduotis3.c

gettingInput.o: cFiles/gettingInput.c
	gcc -c cFiles/gettingInput.c

inputValidation.o: cFiles/inputValidation.c
	gcc -c cFiles/inputValidation.c

convertingText.o: cFiles/convertingText.c
	gcc -c cFiles/convertingText.c

clean:
	del *.o output.exe