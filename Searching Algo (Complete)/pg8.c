#include <stdio.h>
// 8. ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM BINARY SEARCH ALGORITHM THROUGH ITERATION.

#include <stdio.h>

int binary_Search(char arr[], int size, char value)
{
    int start = 0, end = size - 1, mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == value)
        {
            return mid;
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
    return -1;
}

int main()
{
    char str[100], value;
    int length, temp;

    printf("Enter the length of the string: ");
    scanf("%d", &length);

    printf("Enter characters of the string:\n");
    for (int i = 0; i < length; i++)
    {
        scanf(" %c", &str[i]); // Use " %c" to capture characters
    }

    printf("Entered string: ");
    for (int j = 0; j < length; j++)
    {
        printf("%c ", str[j]);
    }
    printf("\n");

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (str[i] > str[j])
            {
                // Swap str[i] and str[j]
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    printf("Sorted string: ");
    for (int i = 0; i < length; i++)
    {
        printf("%c ", str[i]);
    }
    printf("\n");

    printf("Enter a character to search in the string: ");
    scanf(" %c", &value);

    int result = binary_Search(str, length, value);

    // Output result
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

/*      output:-
    Enter the length of the string: 5
    Enter characters of the string:
    dfcxt
    Entered string: d f c x t
    Sorted string: c d f t x
    Enter a character to search in the string: x
    Character found at index: 4

    Enter the length of the string: 5
        Enter characters of the string:
        vsgtg
        Entered string: v s g t g
        Sorted string: g g s t v
        Enter a character to search in the string: g
        Character found at index: 0
          */