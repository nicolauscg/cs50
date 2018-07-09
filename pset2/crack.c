#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

void incrementChar(char string[], int index);

int main(int argc, string argv[])
{
    // ensure proper usage
    if(argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    // gets salt
    char salt[15] = {};
    strncpy(salt, argv[1], 2);
    salt[2] = '\0';
    
    // brute force
    char test[5] = {'\0', '\0', '\0', '\0', '\0'};
    do
    {
        incrementChar(test, 0);
        if(strcmp(crypt(test, salt), argv[1]) == 0)
        {
            printf("%s\n", test);
            return 0;
        }
    }while(test[4] == '\0');
    
    printf("password not found\n");
    return 0;
}

// generates A-Z, a-z and carry over if necessary
void incrementChar(char string[], int index)
{
    if (string[index] == '\0')
    {
        string[index] = 'A';
    }else if (string[index] == 'Z')
    {
        string[index] = 'a';
    }else if (string[index] == 'z')
    {
        string[index] = 'A';
        incrementChar(string, index + 1);
    }else
    {
        string[index]++;
    }
}