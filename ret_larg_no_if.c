/* returns the number that is the largest without an if statment. Will return
   the largest value of x and y */

#include <stdio.h>
#include <inttypes.h>


#define MASK 0x000000001

/* written for 32 bit */

int32_t largest_of(int32_t x, int32_t y)
{
    int32_t temp = x - y; /* will be negetive if y is greater than x */
    int32_t sign = 0;     /* sign of temp +/- */

    sign = temp >> 31;    /* 31 = 32-bit, 63 = 64bit */

    /* if temp is neg. sign fills each bit with 1 rather than 0. And vice versa.
       To ignore this we will bitmask off everything except the 2^0 bit */
    sign &= MASK;

    return x - (sign*temp);
}

int main()
{
    int32_t x = 5;    /* small */
    int32_t y = 45;   /* large */
    int32_t res = 0;  /* result of largest_of */

    res = largest_of(x,y);

    printf("\nres = %d\n", res);

    return 0;
} 

