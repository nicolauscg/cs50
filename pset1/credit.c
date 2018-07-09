#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    
    
    long cc_num, divisor = 100;
    int digit, sum = 0, length = 0;
    int id = 0;
    
    printf("Number : ");
    cc_num = get_long_long();
    
    long x = cc_num; //counts the length of input
    do
    {
        x /= 10;
        length++;
    }while(x != 0);
    
    long first_two_digit = cc_num / pow(10, length - 2); //extracts first two digits of input
    
    //checks for company identifier
    if(length == 15 && (first_two_digit == 34 || first_two_digit == 37))
    {
        id = 1; //id for AMEX
    }else if(length == 16 && first_two_digit >= 51 && first_two_digit <= 55)
    {
        id = 2; //id for MasterCard
    }else if( (length == 13 || length == 16) && first_two_digit >= 40 && first_two_digit <= 49)
    {
        id = 3; //id for Visa
    }else
    {
        id = 0; //id for invalid
    }
    
    if(id != 0) //skips check digit algorithm if invalid
    {
        for(int i=1; i< length; i+=2)
        {
            digit = (cc_num%divisor)/(divisor*0.1);
            digit *= 2;
            
            if( digit >= 10)
            {
                sum += digit%10;
                sum += digit/10;
            }else
            {
                sum += digit;
            }
            divisor *= 100;
        }
        
        divisor = 10;
        for(int i=0; i< length; i+=2)
        {
            digit = (cc_num%divisor)/(divisor*0.1);
            sum += digit;
            divisor *= 100;
        }
        if(sum%10 != 0)
        {
            id = 0;
        }
    }
    
    switch(id) //prints output
    {
    case 1 :
    printf("AMEX\n");
    break;
        case 2 :
        printf("MASTERCARD\n");
        break;
    case 3 :
    printf("VISA\n");
    break;
        default :
        printf("INVALID\n");
        break;
    }
    
    return 0;
}