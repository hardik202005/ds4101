
// 4. ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM LINEAR SEARCH ALGORITHM THROUGH ITERATION.

#include <stdio.h>

int main()
{

    char arr[100], value;
    int length, i, j;

    printf("Enter the length of the string : ");
    scanf("%d", &length);
    printf("The length of the string is = %d", length);
    printf("\n");

    printf("Enter values for string : \n");
    for (i = 1; i <= length; i++)
    {
        scanf("%s", &arr[i]);
    }

    printf("Entered string is : ");

    for (j = 1; j <= length; j++)
    {
        printf("%c\t", arr[j]);
    }
    printf("\n");

    printf("Enter a value to search in the string : ");
    scanf("%s", &value);
    printf("Value to be searched in the string is : %c \n", value);

    void search(char arr[], int size, char value);
    search(arr, length, value);

    return 0;
}

void search(char arr[], int size, char value)
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


    /*  Output:-

    Enter the length of the string : 6
    The length of the string is = 6
    Enter values for string : 
    a
    e
    i
    o
    u
    g
    Entered string is : a   e       i       o       u       g
    Enter a value to search in the string : g
    Value to be searched in the string is : g 
    The value found at index : 6 

    Enter the length of the string : 5
    The length of the string is = 5
    Enter values for string : 
    a
    w
    q
    r
    t
    Entered string is : a   w       q       r       t
    Enter a value to search in the string : p
    Value to be searched in the string is : p 
    Value not found !   



      */
