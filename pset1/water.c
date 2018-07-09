#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int s;
    printf("Minutes : ");
    s= get_int();
    printf("Bottles : %d\n", s*12);
    
    return 0;
}