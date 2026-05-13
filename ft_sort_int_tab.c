#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
{
    int i;
    int temp;

    i = 0;
    while (i < size - 1)
    {
        if (tab[i] > tab[i + 1])
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;

            i = 0;
        }
        else
        {
            i++;
        }
    }
}

int main(void)
{
    int arr[5] = {5, 1, 4, 2, 3};
    int i;

    ft_sort_int_tab(arr, 5);

    i = 0;
    while (i < 5)
    {
        printf("%d ", arr[i]);
        i++;
    }

    return (0);
}