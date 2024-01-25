#include <stdio.h>
#include <time.h>

double calc_time(clock_t begin, clock_t end)
{
    double time = ((double)end - begin) / CLOCKS_PER_SEC;
    return time;
}

void InsertionSort(int *vet, int tam, double *time)
{
    int i, j, temp;
    clock_t begin = clock(); //starts the clock
    for(i = 1; i < tam; i++)
    {
        temp = vet[i];
        for(j = i - 1; j >= 0 && vet[j] > temp; j--) vet[j + 1] = vet[j];
        vet[j + 1] = temp;
    }
    clock_t end = clock(); // stops the clock
    *time = calc_time(begin, end);
}

int main()
{
    int socorro[5] = {5,4,3,2,1};
    double tempo;
    InsertionSort(socorro, 5, &tempo);
    for(int i = 0; i < 5; i++) printf("%i", socorro[i]);
}
