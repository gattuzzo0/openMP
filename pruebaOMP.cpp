
#include <stdio.h>
#include <omp.h>

int tid;
#define N 8

int main()
{
    int arr1[1], arr2[1], i, elementos;
    printf("Cuantos elementos desea agregar?");
    scanf_s("%d", &elementos);


    for (i = 0; i < elementos; i++) {
        printf("Introduzca el elementos %d  del array A\n", i);
        scanf_s("%d", &arr1);
    }

    for (i = 0; i < elementos; i++) {
        printf("Introduzca el elementos %d  del array B\n", i);
        scanf_s("%d", &arr2);
    }

    int result[N], sum=0;
    int tid;
    /*
#pragma omp parallel num_threads(elementos)
    {
        tid = omp_get_thread_num();
        result[tid] = arr1[tid] + arr2[tid];
        printf("El resultado del hilo[%d] es = %d\n", tid, result[tid]);
    }
    */

    // parallelized
#pragma omp parallel for reduction(+:sum)    
    for (int n = 0; n < elementos; n++)
    {
        //tid = omp_get_thread_num();
        result[n] = arr1[n] + arr2[n];
        sum += result[n];  // add element to total sum (one thread at a time)
    }

    // print sum and exit
    printf("El resultado es = %d\n", result);
    delete[] result;
    return 0;


}