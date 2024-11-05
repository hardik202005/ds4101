// 7. ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM BINARY SEARCH ALGORITHM THROUGH RECURSION.

#include <stdio.h>

int binary_Search(int arr[], int start, int end, int value)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value)
        {
            return mid; // Value found
        }
        else if (arr[mid] > value)
        {
            return binary_Search(arr, start, mid - 1, value);
        }
        else
        {
            return binary_Search(arr, mid + 1, end, value);
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
                // Swap arr[i] and arr[j]
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

    int result = binary_Search(arr, 0, length - 1, value);

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

/*      output:-
    Enter the size of the array: 7
    Enter elements of the array:
    32
    56
    89
    22
    56
    745
    5
    Enter a value to search in the array: 22
    Sorted array:
    5 22 32 56 56 89 745
    Value found at index: 1


    Enter the size of the array: 5
    Enter elements of the array:
    43
    57
    89
    32
    67
    Enter a value to search in the array: 67
    Sorted array:
    32 43 57 67 89
    Value found at index: 3


*/