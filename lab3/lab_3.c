#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
omp_lock_t lock;

#define NUMPOINT 9000000 // кількість точок
#define PI 3.1415926536

// функція обчислення визначеного інтеграла
double Integral(double *x, double step) 
{
	double value = 0;
	for (int i = 0; i < NUMPOINT; i++) 
	{
		value += x[i];
	}
	value *= step;
	return value;
}

int main(int argc, char * argv[]) 
{
	int n, i;
	double *f, step, x, S, start_time, end_time, tick;
	omp_init_lock(&lock);
	start_time = omp_get_wtime();
	#pragma omp parallel num_threads(1) // вибираємо кількість потоків для обчислення
	{
		#pragma omp barrier
		{
			omp_set_lock(&lock); 
			system("chcp 1251");
			system("cls");
			f = (double*)malloc(NUMPOINT * sizeof(double));
			printf("Number of points = %d\n", NUMPOINT);
			printf("\n");
			step = PI / NUMPOINT; // розмрі кроку (висота трапеції)
			printf("Step size = %lf\n", step);
			printf("\n");
			x = 0.0;
			omp_unset_lock(&lock);
			n = omp_get_thread_num();
			printf("Thread %d\n", n);
		}
	}
	
	omp_destroy_lock(&lock);
	
	# pragma omp for
	for (i = 0; i<NUMPOINT; i++) 
	{
		f[i] = sin(x); //задаю функцію
		x += step;
	}
	S = Integral(f, step); // рахую інтеграл
	printf("Value of the integral = %lf\n", S);
	printf("\n");
	end_time = omp_get_wtime ();
	tick = omp_get_wtick ();
	printf ("Time to measure %lf\n", end_time - start_time); // час на замір
	printf("\n");
	printf ("Timer accuracy %lf\n", tick); // Точність таймера
	getchar();
	
	
return 0;
}



