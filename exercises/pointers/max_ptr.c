/*@
	requires \valid(x) && \valid(y);
	ensures *x >= *y;
	assigns \nothing;
	ensures (*x == \old(*x) && *y == \old(*y)) ||
        	(*x == \old(*y) && *y == \old(*x));
*/

void max_ptr(int* x, int* y)
{
    if (*y > *x) {
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }
}

int v = 5;

void main(void)
{
    int x = 10;
    int y = 7;
    max_ptr(&x, &y);
    //@ assert x == 10;
    //@ assert y == 7;
    //@ assert v == 5;

    x = 8;
    y = 15;
    max_ptr(&x, &y);
    //@ assert x == 15;
    //@ assert y == 8;
    //@ assert v == 5;
}

