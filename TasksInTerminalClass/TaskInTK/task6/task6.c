//Savchuk Anton 12.11.21
#include <stdio.h>

int reverse(int num, int result){
	if (num)
	{
		return reverse(num / 10, (result * 10) + (num % 10));
	}

	return result;
}

int Reverse(int num){

	return reverse(num, 0);
}

int main(){

	printf("%d\n", Reverse(123456));

	return 0;
}