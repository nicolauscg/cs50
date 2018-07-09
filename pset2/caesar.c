#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string text;
    int lenText, key;

    //validation for correct usage
    if(argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    //gets input from user
    printf("plaintext: ");
    text = get_string();
    lenText = strlen(text);

    //converts key to integer
    key = atoi(argv[1]);
    key = key%26;
    printf("ciphertext: ");

    //converts to ciphered text, using modulo to round back to A, from Z onwards
    for(int i=0; i<lenText; i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            printf("%c", (text[i] + key - 'a')%26 + 'a');
        }else if(text[i] >= 'A' && text[i] <= 'Z')
        {
            printf("%c", (text[i] + key - 'A')%26 + 'A');
        }else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");

    return 0;
}