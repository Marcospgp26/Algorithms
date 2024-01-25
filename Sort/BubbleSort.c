#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calc_time(clock_t begin, clock_t end)
{
    double time = ((double)(end - begin)) / CLOCKS_PER_SEC;
    return time;
}

void BubbleSort(int *vet, int siz, double *time) //receives the array, the array size and a variable to save the time
{
    int i, j, temp, flag;
    char c;
    clock_t begin = clock(); //Start counting the execution time of the function
    for(i = 0; i < siz; i++)
    {
        flag = 0; //redefine the flag to 0
        for(j = 0; j < siz - i - 1; j++)
        {
            if(vet[j] > vet[j +1] )
            {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                flag = 1;
            }
        }
        if(!flag) break; //this means that the array is already sorted;
    }

    clock_t end = clock(); //stops counting the time
    *time = calc_time(begin, end);//returns the time that the code stayed in the function
}

