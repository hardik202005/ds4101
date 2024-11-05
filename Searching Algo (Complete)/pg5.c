#include <stdio.h>
// 5. ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM BINARY SEARCH ALGORITHM THROUGH ITERATION.

#include <stdio.h>

int binary_Search(int arr[], int size, int value)
{
    int start = 0, end = size - 1, mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == value)
        {
            return mid; // Value found
        }
        else if (arr[mid] > value)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1; // Value not found
}

// Main function
int main()
{
    int arr[100], length, value, temp;

    printf("Enter the size of the array: ");
    scanf("%d", &length);

    printf("Enter elements of the array: \n");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter a value to search in the array: ");
    scanf("%d", &value);

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted array: \n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int result = binary_Search(arr, length, value);

    if (result == -1)
    {
        printf("Value not found in the array.\n");
    }
    else
    {
        printf("Value found at index: %d\n", result);
    }

    return 0;
}

/*           output:-
    Enter the size of the array: 5
    Enter elements of the array:
    32
    24
    67
    21
    5
    Enter a value to search in the array: 75
    Sorted array:
    5 21 24 32 67
    Value not found in the array.

    Enter the size of the array: 6
    Enter elements of the array:
    2
    34
    6
    89
    1
    24
    Enter a value to search in the array: 6
    Sorted array:
    1 2 6 24 34 89
    Value found at index: 2
    */