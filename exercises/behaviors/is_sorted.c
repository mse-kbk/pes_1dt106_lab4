/*@
    requires len >= 1;
    requires \valid_read(arr + (0 .. len-1));
    
    assigns \nothing;
    
    behavior sorted:
        assumes \forall int i, j; 0 <= i <= j < len ==> arr[i] <= arr[j];
        ensures \result == 1;
    
    behavior not_sorted:
        assumes \exists int i, j; 0 <= i <= j < len && arr[i] > arr[j];
        ensures \result == 0;
    
    complete behaviors;
    disjoint behaviors;
*/
int is_sorted(int* arr, int len) 
{
	if (len == 1) {
        return 1;
    }
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall int j, k; 0 <= j <= k < i ==> arr[j] <= arr[k];
        loop assigns i;
        loop variant len - i;
    */
    for (int i = 1; i < len; i++) {
        if (arr[i-1] > arr[i]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int a1[] = {1,2,3};
    int a2[] = {2,1,3}; 

    int r1 = is_sorted(a1, 3); 
    int r2 = is_sorted(a2, 3); 

    //@ assert r1 == 1;
    //@ assert r2 == 0; 
}
