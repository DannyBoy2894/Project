#include <stdio.h>
#include <stdafx.h>
#include <math.h>
#include <string.h>

// Declare function so the program can expect one to be called.
int functionEncrypt (int m, int k);
int functionDecrypt (int c, int k);

int main()
{
    FILE *inputFile, *outputFile; // these are pointers to the files you will be reading from and writing to.
    int m, i, c, k, input;
    char e, d;
    
    char inMessage [100];
    char outMessage [100];
    
    errno_t err; // checks program for errors and tells you what they are.
    
    m = 0;
    i = 0;
    c = 0;
    k = 0;
    
    char alphaB[27] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    // open an input file
    err = fopen_s(&inputFile, "Input.dat", "r"); // this open the file specifically for reading (note "r").
    if (err == 0) // checking for errors
    {
        printf_s("The file Input.dat was opened\n");
    }
    else
    {
        Printf_s("the file Input.dat could not open\n")
    }
    
    // open and output file
    err = fopen_s(&outputFile, "Output.dat", "w");
    if (err == 0)
    {
        printf_s("The file Output.dat was opened\n")
    }
    else
    {
        printf_s("The file Output.dat was not opened\n")
    }
    
    while (!feof (inputFile)) // !=not, feof=end of file, essentially saying read until the end of the file.
    {
        fscanf_s(inputFile, "%d", &k); // here you have read the input file
        printf_s("The message read from the input file is as follows;\n\n");
        fgets(inMessage, 100, inputFile); // fscanf_s doesnt like spaces so we use fgets here instead.
        printf_s("%s\n", inMessage); // printing to the serial monitor the message it read.
        printf_s("%d\n\n", k);
        printf_s("If this message needs to be Encrypted, type '1'\nOtherwise if the message needs to be Decrypted, type '2'.\n");
        scanf_s("%d", &input);
        
        if(input == 1)
        {
            i = 0;
            m = inMessage[i];
            outMessage[i] = functionEncrypt (m, k);
            gets_s(outMessage, 100);
            printf_s("%s\n", outMessage);
            i++;
        }
        else if(input == 2)
        {
            c = inMessage[i];
            outMessage[i] = functionDecrypt (c, k);
            gets_s(outMessage, 100);
            printf_s("%s\n", outMessage);
            i++;
        }
        else if(input != 1 || 2)
        {
            printf_s("Input does not accept.\n");
        }
    }
    
    // closing all open files
    int numclosed = _fcloseall();
    printf("Number of files closed by _fcloseall: %u\n",numclosed);
    
    return 0;
}

int functionEncrypt(int m, int k) // function to encrypt message
{
    int e;
    e = (m + k) % 26;
    return e;
}

int functionDecrypt(int c, int k) // function the decrypt message
{
    int d;
    d = (c - k) % 26;
    return d;
}
