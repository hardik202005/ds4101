// ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM LINEAR SEARCH ALGORITHM THROUGH RECURSION.

#include <stdio.h>

int linearSearch(int arr[], int size, int value, int index)
{
    if (index >= size)
    {
        return -1; 
    }
    if (arr[index] == value)
    {
        return index; 
    }
    return linearSearch(arr, size, value, index + 1); // Recur for the next index
}

int main()
{
    int size, value;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d integers: \n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the integer to search for: ");
    scanf("%d", &value);

    int result = linearSearch(arr, size, value, 0);

    if (result == -1)
    {
        printf("Value not found in the array.\n");
    }
    else
    {
        printf("Value found at index %d.\n", result);
    }

    return 0;
}


/*
        Output:-

        Enter the size of the array: 5
        Enter 5 integers: 
        21
        24
        5
        32
        67
        Enter the integer to search for: 2
        Value not found in the array.

        Enter the size of the array: 5
        Enter 5 integers: 
        43
        67
        24
        89
        5
        Enter the integer to search for: 24
        Value found at index 2.
*/