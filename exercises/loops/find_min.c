#include <limits.h>

/*@
 requires 1 <= len;
 requires \valid_read(arr + (0 .. len-1));
 requires \forall int i; 0 <= i < len ==> (INT_MIN <= arr[i] <= INT_MAX);
 assigns \nothing;
 ensures \exists int i; 0 <= i < len && arr[i] == \result;
 ensures \forall int i; 0 <= i < len ==> arr[i] >= \result;

 */

int find_min(int* arr, int len)
{
	int smallest = arr[0];
/*@
	loop invariant 1 <= i <= len;
   	loop invariant \exists int k; 0 <= k < i && smallest == arr[k];
    	loop invariant \forall int j; 0 <= j < i ==> arr[j] >= smallest;
    	loop assigns i, smallest;
    	loop variant len - i;
 */
	for (int i = 1; i< len; i++) {
		if (arr[i] < smallest) {
			smallest = arr[i];
		}
	}
	return smallest;

}

void main(void)
{
    int a[] = {3, 5, 18, 2, 12};
    int r = find_min(a, 5);
    //@ assert r == 2;
}
