#include <limits.h>

/*@
    requires \valid(x);
    requires \valid_read(y);
    requires \separated(x, y);
    requires INT_MIN <= (*x-*y) <= INT_MAX;
        
    assigns *x;
    
    ensures *x == \old(*x) - *y;
    ensures *y == \old(*y);
*/
void decr_by(int* x, int const* y)
{
  
    *x = *x - *y;
}

void main(void)
{
    int x = 7;
    int y = 3;
    decr_by(&x, &y);
	//@assert x == 4;
	//@ assert y == 3;
}

