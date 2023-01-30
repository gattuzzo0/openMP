

//#include "pch.h"
#include <iostream>
#include <omp.h>

#define N 30
#define chunk 10
#define mostrar 10

void imprimearreglo(float* d);

int main()
{
	std:: cout << "Sumando Arreglos en Paralelo!\n";
	float a[N], b[N], c[N];
	int i;


	for (i = 0; i < N; i++)
	{
		a[i] = i;
		b[i] = (i + 3) * 1;
	}

	int pedazos = chunk;

	#pragma omp parallel for schedule(static, pedazos) 
	for (i = 0; i < N; i++) {
		c[i] = a[i] + b[i];
		printf("La suma de los 2 arrays en la posicion: c[%d] es igual= %d. Esta operacion se realizo en el hilo %d\n", i, c[i], omp_get_thread_num());

	}


	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimearreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimearreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c (La suma vertical de ellos): " << std::endl;
	imprimearreglo(c);
	}
		

void imprimearreglo(float *d)
{
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " -";
	std::cout << std::endl;

}




