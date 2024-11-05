#include <stdio.h>
// 1. ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM LINEAR SEARCH ALGORITHM THROUGH ITERATION.
int main()
{

    int arr[100];
    int value, length, i, j;

    printf("Enter the length of the array : ");
    scanf("%d", &length);
    printf("The length of the array is = %d", length);
    printf("\n");

    printf("Enter values for array : \n");
    for (i = 1; i <= length; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Entered array is : ");

    for (j = 1; j <= length; j++)
    {
        printf("%d \t", arr[j]);
    }
    printf("\n");

    printf("Enter a value to search in the array : ");
    scanf("%d", &value);
    printf("Value to be searched in the array is : %d \n", value);

    void search(int arr[], int size, int value);
    search(arr, length, value);

    return 0;
}

void search(int arr[], int size, int value)
{
    int counter = 0;
    for (int p = 1; p <= size; p++)
    {
        if (arr[p] == value)
        {
            printf("The value found at index : %d ", p);
            counter++;
            break;
        }
    }
    if (counter == 0)
    {
        printf("Value not found !");
    }
}

/*     Output :-

    Enter the length of the array : 7
    The length of the array is = 7
    Enter values for array :
    12
    32
    56
    43
    67
    32
    23
    Entered array is : 12   32      56      43      67      32      23
    Enter a value to search in the array : 56
    Value to be searched in the array is : 56
    The value found at index : 3


    Enter the length of the array : 5
    The length of the array is = 5
    Enter values for array :
    12
    52
    78
    96
    4
    Entered array is : 12   52      78      96      4
    Enter a value to search in the array : 1
    Value to be searched in the array is : 1
    Value not found !

      */