#include <stdio.h>
#include <time.h>

double calc_time(clock_t begin, clock_t ending)
{
    double time = ((double)(ending - begin)) / CLOCKS_PER_SEC;
    return time;
}

void SelectionSort(int *vet, int siz, double *time)
{
    int i, j, temp, small;
    clock_t begin = clock();
    for(i = 0; i < siz - 1; i++)
    {
        small = i;
        for(j = i + 1; j < siz; j++)
            if(vet[j] < vet[small]) small = j;
        temp = vet[i];
        vet[i] = vet[small];
        vet[small] = temp;
    }

    clock_t ending = clock();
    *time = calc_time(begin, ending);
}
