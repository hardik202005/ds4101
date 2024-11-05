/*  13. IMPLEMENT THE TOWER OF HANOI USING STACKS. */

void towerofHanoi(int n, char fromTower, char toTower, char auxTower)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from %c tower to %c tower ", fromTower, toTower);
        return;
    }
    towerofHanoi(n - 1, fromTower, auxTower, toTower);
    printf("\nMove disk %d from %c tower to %c tower ", n, fromTower, toTower);
    towerofHanoi(n - 1, auxTower, toTower, fromTower);
}

#include <stdio.h>

int main()
{
    towerofHanoi(2,'A','C','B');
    return 0;
}
