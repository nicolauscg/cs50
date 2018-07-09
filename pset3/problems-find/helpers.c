/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n <= 0)
    {
        return false;
    }
    
    int left = 0, right = n - 1;
    int mid;
    
    while(right - left >= 0)
    {
        mid = (left + right)/2;
        if(values[mid] == value)
        {
            return true;
        }else if(values[mid] > value)
        {
            right = mid - 1;
            
        }else if(values[mid] < value)
        {
            left = mid + 1;
        }
        
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    int count[65536]={};
    
    // adds key values of unsorted array to indices in count array
    for (int i=0; i<n; i++)
    {
        count[values[i]]++;
    }
    
    // i : position of sorted array index
    // j : position of count array
    int j = 0;
    for(int i = 0; i<n; )
    {
        while(count[j] != 0)
        {
            values[i] = j;
            count[j]--;
            i++;
        }
        j++;
    }
    
    return;
}
