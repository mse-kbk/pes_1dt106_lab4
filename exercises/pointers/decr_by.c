void decr_by(int* x, int const* y)
{
    *x = *x - *y;
}

void main(void)
{
    int x = 7;
    int y = 3;
    decr_by(&x, &y);
    //@ assert x == 4;
    //@ assert y == 3;
}
