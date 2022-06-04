#include "Func.h"

long double Factorial(double x) {																
	if (x < 0) return 0;																		
	if (x == 1 || x == 0) return 1;																
	return x * Factorial(x - 1);																
}

struct Answer sin_func(double x, double eps, int n, int i) {									
	struct Answer result;																		
	result.etalon = sin(x);																		
	result.f_x = 0;																			
	for (i = 1; i <= n; i++) {																
		result.f_x += pow(-1, i + 1) * pow(x, 2 * i - 1) / (long double)Factorial(2 * i - 1);	
		if (fabs(result.etalon - result.f_x) < eps) 
			break;										
	}
	result.difference = fabs(result.etalon - result.f_x);										
	result.count = i;																			
	return result;																				
}

struct Answer cos_func(double x, double eps, int N, int i) {									
	struct Answer result;																		
	result.etalon = cos(x);																		
	result.f_x = 0;																				
	for (i = 0; i < N; i++) {																	
		result.f_x += pow(-1, i) * pow(x, 2 * i) / (long double)Factorial(2 * i);				
		if (fabs(result.etalon - result.f_x) < eps) 
			break;										
	}
	result.difference = fabs(result.etalon - result.f_x);										
	result.count = i;																			
	return result;																				
}

struct Answer exp_func(double x, double eps, int N, int i) {									
	struct Answer result;																		
	result.etalon = exp(x);																		
	result.f_x = 0;																				
	for (i = 0; i < N; i++) {																	
		result.f_x += pow(x, i) / (long double)Factorial(i);									
		if (fabs(result.etalon - result.f_x < eps)) 
			break;										
	}
	result.difference = fabs(result.etalon - result.f_x);										
	result.count = i;																			
	return result;																				
}

struct Answer arccos_func(double x, double eps, int N, int i) {
	struct Answer result;
	result.etalon = acos(x);
	result.f_x = 0;
	for (i = 0; i < N; i++) {
		result.f_x += ((2 * i - 1) * pow(x, 2 * i - 1)) / (long double)(2 * i) * (2 * i + 1);
		if (fabs(result.etalon - result.f_x < eps)) 
			break;
	}
	result.difference = fabs(result.etalon - result.f_x);
	result.count = i;
	return result;
}
