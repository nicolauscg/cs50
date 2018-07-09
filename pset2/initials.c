#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string s = get_string();
    int len = strlen(s);
    for(int i=0; i<len; i++)
    {
        s[i] = toupper(s[i]);
        if(s[i] >= 'A' && s[i <= 'Z'])
        {
            if(i == 0)
            {
                printf("%c", s[i]);
            }else if(s[i - 1] == ' ')
            {
                printf("%c", s[i]);
            }
        }
    }
    printf("\n");
    return 0;
}