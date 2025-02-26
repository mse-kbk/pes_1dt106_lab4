/*@
    requires n >= 0;
    requires \valid_read(a + (0 .. n-1));
    requires \valid_read(b + (0 .. n-1));

    assigns \nothing;

    behavior equal:
        assumes \forall int i; 0 <= i < n ==> a[i] == b[i];
        ensures \result == 1;
    
    behavior not_equal:
        assumes \exists int i; 0 <= i < n && a[i] != b[i];
        ensures \result == 0;
    
    complete behaviors;
    disjoint behaviors;
*/
int array_equals(int* a, int* b, int n);
