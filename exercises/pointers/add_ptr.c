#include <limits.h>

 /*@
	requires INT_MIN <= (*a+*b) <= INT_MAX;
        requires \valid(a) && \valid(b);
	ensures \result == *a + *b;
	assigns \nothing;
*/
int add_ptr(int* a, int* b)
{
	int res = 0;
	res = *a + *b;
	return res;
    
}

void main(void)
{
    int a = 13;
    int b = 15;
    int r = add_ptr(&a, &b);
    //@ assert r == 28;
}
