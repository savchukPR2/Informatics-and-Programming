
#include "Main.h"


int main() {

	int VariantOfProg, VariantOfFunction, n, NMax, count, i, restart; 
	double x, etalon, difference, eps;								  
	n = 1000, count = 0, i = 0, restart = 0, x = 1, etalon = 0, difference = 0, eps = 0.000001, NMax = 25; 
	srand(time(NULL)); 

	printf("Select a program:\n");											
	printf("1. Single function calculation.\n");    
	printf("2. Serial experiment.\nEnter number: ");							
	scanf_s("%d", &VariantOfProg);											

	printf("Select function:\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. arccos(x)\nEnter number: "); 
	scanf_s("%d", &VariantOfFunction);														 
	printf("Enter x: ");		
	scanf_s("%lf", &x);		

	switch (VariantOfFunction) { 
	case 1:
		func_type = sin_func; 
		break;
	case 2:
		func_type = cos_func;
		break;
	case 3:
		func_type = exp_func;
		break;
	case 4:
		func_type = arccos_func; 
		break;
	default:
		break;
	}

	switch (VariantOfProg)
	{
	case 1:
		printf("Enter eps (accuracy) (from 0.000001 and more): "); 
		scanf_s("%lf", &eps);														 
		printf("Enter the number of elements to calculate (N - from 1 to 1000): ");  
		scanf_s("%d", &n);															 

		res = func_type(x, eps, n, i); 

		system("cls");													
		printf("Settings: \n");											
		printf("X = %lf\nN = %d\nEPS = %lf\nResult:\n", x, n, eps);		
		printf("Etalon value: %lf\n", res.etalon);						
		printf("Custom value: %Lf\n", res.f_x);							
		printf("Difference: %lf\n", res.difference);					
		printf("The number of terms: %d\n", res.count);					
		getch();														
		break;
	case 2:
		printf("Enter the number of experiments (NMax - 1 to 25): ");   
		scanf_s("%d", &NMax);										   

		for (int i = 1, n = 1; i <= NMax; i++, n++) {				    
			res = func_type(x, eps, n, i);							    
			printf("Results:\n%2d. Etalon: %lf \t", i, res.etalon);   
			printf("Result: %Lf \t", res.f_x);					       
			printf("Difference: %lf \t", res.difference);			    
			printf("Summand: %d \n", res.count);				        
		}
		getch();														
	default:
		break;
	}

	printf("\nRestart? (1/0) -> ");										
	scanf_s("%d", &restart);											
	system("cls");														
	if (restart == 1) main();											
	else return 0;														
}


