#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    
    do //validation
    {
        printf("Height : ");
        height = get_int();
    }while(height < 0 || height > 23);
    
    for(int n=1; n<=height; n++)
    {
        int i, j;
        for(i=0; i<(height - n); i++) //prints left half of pyramid
        {
            printf(" ");
        }
        for(j=0; j<n; j++)
        {
            printf("#");
        }
        
        printf("  "); //adds space in between
        
        for(j=0; j<n; j++) //prints right half of pyramid
        {
            printf("#");
        }
        
        printf("\n");
    }
}