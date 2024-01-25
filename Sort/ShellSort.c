#include <stdio.h>
#include <time.h>

double calc_time(clock_t begin, clock_t end)
{
    double time = ((double)end - begin) / CLOCKS_PER_SEC;
    return time;
}

void ShellSort(int *arr, int siz, double *time)
{
    int i,j, h = 1, aux;

    clock_t begin = clock();
    do{ h = (3 * h + 1);}while(h < siz);
    do
    {
        h /=3;
        for(i = h; i < siz; i++)
        {
            j = i;
            aux = arr[i];
            while(arr[j - h] > aux)
            {
                arr[j] = arr[j - h];
                j - h;
                if(j < h) break;
            }
            arr[j] = aux;
        }
    }while(h != 1);
    clock_t end = clock();
    *time = calc_time(begin, end);
}
