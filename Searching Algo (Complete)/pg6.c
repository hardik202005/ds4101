// 6. ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM BINARY SEARCH ALGORITHM THROUGH RECURSION.

#include <stdio.h>

// Function to perform binary search recursively
int binary_Search(char arr[], int start, int end, char value)
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
            return binary_Search(arr, start, mid - 1, value); // Search in the left half
        }
        else
        {
            return binary_Search(arr, mid + 1, end, value); // Search in the right half
        }
    }
    return -1; // Value not found
}

int main()
{
    char str[100], value;
    int length;

    printf("Enter a string: ");
    scanf("%s", str);
    length = 0;
    for (int i = 0; str[i]; i++)
    {
        length++;
    }

    printf("Enter a character to search in the string: ");
    scanf(" %c", &value);

    // Sort the string (Simple selection sort)
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (str[i] > str[j])
            {
                // Swap str[i] and str[j]
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    printf("Sorted string: %s\n", str);

    int result = binary_Search(str, 0, length - 1, value);

    if (result == -1)
    {
        printf("Character not found in the string.\n");
    }
    else
    {
        printf("Character found at index: %d\n", result);
    }

    return 0;
}


/*          output:- 

        Enter a string: gsrter 
        Enter a character to search in the string: t
        Sorted string: egrrst
        Character found at index: 5

        Enter a string: gagyttfv
        Enter a character to search in the string: v
        Sorted string: afggttvy
        Character found at index: 6
*/