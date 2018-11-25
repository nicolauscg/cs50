#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage ./recover image\n");
        return 1;
    }
    
    char *file = argv[1];
    
    FILE *ptr = fopen(file, "r");
    if (ptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", file);
        return 2;
    }
    
    FILE *img = NULL;
    unsigned char buffer[512];
    char filename[10];
    int count = 0;
    bool found = false;
    
    while(fread(buffer, 512, 1, ptr) == 1)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(found == true)
            {
                fclose(img);
            }
            found = true;
            
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "a");
            
            count++;
        }
        
        if(found == true)
        {
            fwrite(buffer, 512, 1, img);
        }
    }
    
    fclose(ptr);
    fclose(img);
    
    return 0;
}