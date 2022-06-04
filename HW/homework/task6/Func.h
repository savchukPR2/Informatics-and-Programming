#ifndef _FUNC_H
#define _FUNC_H
#include <stdio.h>
#include <time.h>
#include <math.h>

struct Answer													
{
																
	double f_x;
	double difference;
	double etalon;
	int count;
}res;															

long double Factorial(double x);								
struct Answer sin_func(double x, double eps, int n, int i);     
struct Answer cos_func(double x, double eps, int N, int i);     
struct Answer exp_func(double x, double eps, int N, int i);     
struct Answer arccos_func(double x, double eps, int N, int i);   


#endif 