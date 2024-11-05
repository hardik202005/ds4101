// 2. ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM LINEAR SEARCH ALGORITHM THROUGH RECURSION.

#include <stdio.h>

int linearSearch(char str[], char ch, int index)
{
    if (str[index] == '\0')
    {
        return -1;
    }
    if (str[index] == ch)
    {
        return index;
    }
    return linearSearch(str, ch, index + 1);
}

int main()
{
    char str[100], ch;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter the character to search for: ");
    scanf(" %c", &ch);

    int result = linearSearch(str, ch, 0);

    if (result == -1)
    {
        printf("Character not found in the string.\n");
    }
    else
    {
        printf("Character found at index %d.\n", result);
    }

    return 0;
}


/*     Output:-

    Enter a string: aeiuo
    Enter the character to search for: t
    Character not found in the string.

    Enter a string: aeiou
    Enter the character to search for: a
    Character found at index 0.

     */