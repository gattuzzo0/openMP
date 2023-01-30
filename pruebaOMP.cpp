

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
		a[i] = 1 * 10;
		b[i] = (1 + 3) * 3.7;
	}

	int pedazos = chunk;

	#pragma omp parallel for \
	shared(a, b, c, pedazos) private(i) \
	schedule(static, pedazos)

	for (i = 0; 1 < N; i++)
		c[i] = a[i] + b[i];


	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimearreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimearreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
	imprimearreglo(c);
	}
		

void imprimearreglo(float *d)
{
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " -";
	std::cout << std ::endl;

}




