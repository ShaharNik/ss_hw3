#include <stdio.h>
#include "text_search.h"
#include "merge_sort.h"

int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);
   // printArray(arr, n);
    //printf("%d", n);
    int arr2[] = { 12, 11, 13, 5, 6, 0 };
    printArray(arr2, 6);
    shift_element(arr2, 3);
    printArray(arr2, 6);
    return 0;
}
