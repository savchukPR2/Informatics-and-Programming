//Anton Savchuk 17.10.21

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef __cplusplus
#define bool int
#define true 1
#define false 0
#endif

#define SIZE 10
#define BAR_LEN 5
#define PROD_LEN 20 
#define MAX_CHECK_COUNT 100


#define SCAN_CURRENT_PRODUCT 1 //Pointer for scanning product
#define SHOW_PRODUCT 2 //Pointer for outputing product
#define ADD_TO_CHECK 3 //Pointer for inputing products in check
#define CREATE_CHECK 4 //Pointer for generating check with products
#define CALCULATE_COST -1 //Pointer for calculating the coast for all products
#define EXIT_PROGRAMM 5 //Pointer for exit
#define SHOW_ALL_PRODUCTS 0
#define SHOW_MENU 6

char products[SIZE][PROD_LEN];
char barcodes[SIZE][BAR_LEN];
float prices[SIZE];
float discounts[SIZE];
int last_prod_index = -1;

int pay_check[MAX_CHECK_COUNT][2];
int check_count = 0;
float cost;


int user_choice() {
	int state = 0;
	while (true) {
		printf("take a number: ");
		scanf_s("%d", &state);
		if ((state >= SHOW_ALL_PRODUCTS) && (state <= SHOW_MENU))
			break;
	}
	return state;
}




void define_products() {

	strcpy_s(products[0], 20,  "Apples(1kg)");
	strcpy_s(products[1], 20, "Bananas(1kg)");
	strcpy_s(products[2], 20, "Pineapple(1kg)");
	strcpy_s(products[3], 20, "Oranges(1kg)");
	strcpy_s(products[4], 20, "Headphones(1 pair)");
	strcpy_s(products[5], 20, "TShort(1 piece)");
	strcpy_s(products[6], 20, "Shampoo(1 piece)");
	strcpy_s(products[7], 20, "Gel Shower(1 piece)");
	strcpy_s(products[8], 20, "Tea(1 bag)");
	strcpy_s(products[9], 20, "Apples(1kg)");

	//define barcodes for each product
	strcpy_s(barcodes[0], 5, "0001");
strcpy_s(barcodes[1], 5, "0002");
strcpy_s(barcodes[2], 5, "0003");
strcpy_s(barcodes[3], 5, "0004");
strcpy_s(barcodes[4], 5, "0005");
strcpy_s(barcodes[5], 5, "0006");
strcpy_s(barcodes[6], 5, "0007");
strcpy_s(barcodes[7], 5, "0008");
strcpy_s(barcodes[8], 5, "0009");
strcpy_s(barcodes[9], 5, "0010");

//define price for each product
prices[0] = 100.0;
prices[1] = 150.0;
prices[2] = 109.0;
prices[3] = 200.0;
prices[4] = 179.0;
prices[5] = 1800.0;
prices[6] = 500.0;
prices[7] = 350.0;
prices[8] = 300.0;
prices[9] = 200.0;

//define discount for each product
discounts[0] = 0;
discounts[1] = 0;
discounts[2] = 0;
discounts[3] = 10.0;
discounts[4] = 5.0;
discounts[5] = 25.0;
discounts[6] = 10.0;
discounts[7] = 40.0;
discounts[8] = 0.0;
discounts[9] = 5.0;

}

show_products() {
	printf("-------------------------------------------------------------------\n");
	printf("Product              \t  cost \t       discount\t       barcode\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%-20s \t %.1f \t\t %.1f \t\t %s\n", products[i], prices[i], discounts[i], barcodes[i]);
	}
	printf("-------------------------------------------------------------------\n");
}

//function for searching product by barcode
bool find_product(char* barcode, int* prod_index) {
	for (int i = 0; i < SIZE; i++) {
		if (strcmp(barcode, barcodes[i]) == 0) {
			*prod_index = i;
			return true;
		}
	}
	return false;
}

//function for scanning products
int scan_product() {
	printf("Input product barcode\n");
	char barcode[BAR_LEN];
	int i;

	scanf_s("%s", &barcode, BAR_LEN);

	if (find_product(barcode, &i))
		last_prod_index = i;
	else
		printf("Didnt find barcode");

}

//function for showing products on the screen and choose your number
int show_product() {
	if (last_prod_index > -1) {
		printf("Product              \t  cost \t       discount\t       barcode\n");
		printf("%-20s \t %.1f \t\t %.1f \t\t %s\n", products[last_prod_index], prices[last_prod_index], discounts[last_prod_index], barcodes[last_prod_index]);
	}
}


//function adding products to check
int add_to_check() {
	if ((check_count >= MAX_CHECK_COUNT) || (last_prod_index < 0))
		return;

	if ((check_count > 0) && (pay_check[check_count - 1][0] == last_prod_index)) {
		pay_check[check_count - 1][1]++;
		printf("Update check %d\n", pay_check[check_count - 1][1]);
	}
	else
	{
		check_count++;
		pay_check[check_count - 1][1] = 1;
		pay_check[check_count - 1][0] = last_prod_index;
		printf("add check %d, check count: %d\n", pay_check[check_count - 1][1], check_count);
	}
}

//function for creating check with products
int create_check() {
	float sum = 0;
	printf("Product              \t  cost \t       discount\t       barcode\n");
	for (int i = 0; i < check_count; i++){
		printf("x* %d %-20s \t %.1f \t\t %.1f \t\t %s\n",pay_check[i][1], products[pay_check[i][0]], prices[pay_check[i][0]], discounts[pay_check[i][0]], barcodes[pay_check[i][0]]);
	}
	sum = calculate_cost();
	printf("All coast is: %.1f\n", sum);
}

//function for caclulating all coast for products in check
int calculate_cost() {
	if (check_count == 0)
		return "There are no products in check";
	for (int i = 0; i < check_count; i++) {
		if (discounts[pay_check[i][0]] > 0) {
			cost = pay_check[i][1] * (prices[pay_check[i][0]] / 100 * (100 - discounts[pay_check[i][0]])) + cost;
		}
		else
			cost = pay_check[i][1] * prices[pay_check[i][0]] + cost;
	}
	return cost;
}

//function for exit programm then user pressing 6
int exit_programm() {
	printf("Exiting programm...\n");
}
show_menu() {
	printf("\nInput the state: \n 0 - show all products\n 1 - scan current product\n 2 - show current product\n 3 - add product to check\n 4 - create check\n 5 - Exit programm\n 6 - Show menu\n");
}

	

int main() {
	define_products();
	printf("\nInput the state: \n 0 - show all products\n 1 - scan current product\n 2 - show current product\n 3 - add product to check\n 4 - create check\n 5 - Exit programm\n 6 - Show menu\n");
	while (true) {
		switch (user_choice())
		{
		case SCAN_CURRENT_PRODUCT:
			scan_product();
			break;
		case SHOW_PRODUCT:
			show_product();
			break;
		case ADD_TO_CHECK:
			add_to_check();
			break;
		case CREATE_CHECK:
			create_check();
			break;
		case CALCULATE_COST:
			calculate_cost();
			break;
		case EXIT_PROGRAMM:
			exit_programm();
			break;
		case SHOW_ALL_PRODUCTS:
			show_products();
			break;
		case SHOW_MENU:
			show_menu();
			break;
		}
	}
}