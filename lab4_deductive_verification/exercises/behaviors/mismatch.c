/*@
    requires n >= 0;
    requires \valid_read(a + (0 .. n-1));
    requires \valid_read(b + (0 .. n-1));
    
    assigns \nothing;
    
    behavior identical:
        assumes \forall int i; 0 <= i < n ==> a[i] == b[i];
        ensures \result == -1;
    
    behavior different:
        assumes \exists int i; 0 <= i < n && a[i] != b[i];
        ensures 0 <= \result < n;
        ensures a[\result] != b[\result];
        ensures \forall int i; 0 <= i < \result ==> a[i] == b[i];
    
    complete behaviors;
    disjoint behaviors;
*/
int mismatch(int* a, int* b, int n)
{
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall int j; 0 <= j < i ==> a[j] == b[j];
        loop assigns i;
        loop variant n - i;
    */
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return i;
        }
    }
    return -1;
}