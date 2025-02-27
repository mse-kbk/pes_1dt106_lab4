/*@ 
    requires \true;
    assigns \nothing;
    ensures \result == x || \result == y;
    ensures \result >= x && \result >= y;
    ensures (x >= y ==> \result == x) && (y >= x ==> \result == y);
*/
int max(int x, int y)
{
    return (x >= y) ? x : y;
}