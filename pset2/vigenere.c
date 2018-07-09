#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string text;
    int lenText, lenKey, j=0;
    
    //validation for correct usage
    if(argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    
    //ensures key consists of only letters, lc and uc
    lenKey = strlen(argv[1]);
    for(int i=0; i<lenKey; i++)
    {
        if(toupper(argv[1][i]) < 'A' || toupper(argv[1][i]) > 'Z')
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }
    
    //gets input from user
    printf("plaintext: ");
    text = get_string();
    lenText = strlen(text);
    int key[lenKey];
    
    //converts key to integer for adding
    for(int i=0; i<lenKey; i++)
    {
        if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            key[i] = argv[1][i] - 'a';
        }else
        {
            key[i] = argv[1][i] - 'A';
        }
    }
    
    printf("ciphertext: ");
    
    //converts to ciphered text, using modulo to round back to A, from Z onwards
    for(int i=0; i<lenText; i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            printf("%c", (text[i] + key[j%lenKey] - 'a')%26 + 'a');
            j++;
        }else if(text[i] >= 'A' && text[i] <= 'Z')
        {
            printf("%c", (text[i] + key[j%lenKey] - 'A')%26 + 'A');
            j++;
        }else
        {
            printf("%c", text[i]);
        }
    }
    
    printf("\n");
    
    return 0;
}    