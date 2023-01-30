

//#include "pch.h"
#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
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
		printf("La suma de los 2 arrays, procesada en el hilo:%d, en la posicion [%d] es igual= %f\n", omp_get_thread_num(), i, c[i]);

	}


	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimearreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimearreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c (suma vertical de a + b): " << std::endl;
	imprimearreglo(c);
	}
		

void imprimearreglo(float *d)
{
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " -";
	std::cout << std::endl;

}




