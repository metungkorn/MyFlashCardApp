#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
    int i;
    int temp;

    i = 0;
    while (i < size / 2)
    {
        temp = tab[i];
        tab[i] = tab[size - 1 - i];
        tab[size - 1 - i] = temp;
        i++;
    }
}

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int i;

    ft_rev_int_tab(arr, 5);

    i = 0;
    while (i < 5)
    {
        printf("%d ", arr[i]);
        i++;
    }

    return (0);
}