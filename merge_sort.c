//
// Created by shaharnik on 09/12/2019.
//
#include <stdio.h>
void shift_element(int* arr, int i)
{

    for (int j = 0; j < i; j++)
    {
        *(arr + j + 1) = *(arr + j);
        //arr[j+1] = arr[j];
    }
}
void insertion_sort(int* arr, int len)
{
    int i, key, j;
    for (i = 1; i < len; i++)
    {
        key = *(arr + i);
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
              greater than key, to one position ahead
              of their current position */
        while (j >= 0 && *(arr + j) > key)
        {
            *(arr + j + 1) = *(arr + j); // shift right
            j--;
        }
        *(arr + j + 1) = key;
        //arr[j + 1] = key;
    }
}
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

