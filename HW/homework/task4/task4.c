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


#define SCAN_CURRENT_PRODUCT 0 //Pointer for scanning product
#define SHOW_PRODUCT 1 //Pointer for outputing product
#define ADD_TO_CHECK 2 //Pointer for inputing products in check
#define CREATE_CHECK 3 //Pointer for generating check with products
#define CALCULATE_COST 4 //Pointer for calculating the coast for all products
#define EXIT_PROGRAMM 5 //Pointer for exit
#define SHOW_ALL_PRODUCTS 6

char products[SIZE][20];
char barcodes[SIZE][5];
int prices[SIZE];
int discounts[SIZE];

int user_choice() {
	int state = 0;
	while (true) {
		printf("\nInput the state: \n 0 - scanning product\n 1 - showing all your products\n 2 - add product in check\n 3 - generate your check\n 4 - calculate cost for your order\n 5 - Exit programm\n 6 - Show all products in the shop\n");
		scanf_s("%d", &state);
		if ((state >= SCAN_CURRENT_PRODUCT) && (state <= SHOW_ALL_PRODUCTS))
			break;
	}
	return state;
}




void define_products() {
	/* products[0][20] = "Apples(1kg)\0";
	products[1][20] = "Bananas(1kg)\0";
	products[2][20] = "Pineapple(1kg)\0";
	products[3][20] = "Oranges(1kg)\0";
	products[4][20] = "Headphones(1 pair)\0";
	products[5][20] = "TShort(1 piece)\0";
	products[6][20] = "Shampoo(1 piece)\0";
	products[7][20] = "Gel Shower(1 piece)\0";
	products[8][20] = "Tea(1 bag)\0";
	products[9][20] = "Apples(1kg)\0"; */
	//define price of products in two-dimensional array
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
	prices[0] = 100;
	prices[1] = 150;
	prices[2] = 109;
	prices[3] = 200;
	prices[4] = 179;
	prices[5] = 1800;
	prices[6] = 500;
	prices[7] = 350;
	prices[8] = 300;
	prices[9] = 200;
	
	//define discount for each product
	discounts[0] = 0;
	discounts[1] = 0;
	discounts[2] = 0;
	discounts[3] = 10;
	discounts[4] = 5;
	discounts[5] = 25;
	discounts[6] = 10;
	discounts[7] = 40;
	discounts[8] = 0;
	discounts[9] = 5;

}

show_products() {
	printf("-------------------------------------------------------------------\n");
	printf("Product              \t  cost \t       discount\t       barcode\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%-20s \t %5d \t\t %5d \t\t %s\n", products[i], prices[i], discounts[i], barcodes[i]);
	}
	printf("-------------------------------------------------------------------\n");
}


//function for scanning products
int scan_product() {
	printf("Scanning product...\n");
}

//function for showing products on the screen and choose your number
int show_product() {
	printf("Showing product...\n");
}


//function adding products to check
int add_to_check() {
	printf("adding product to check...\n");
}

//function for creating check with products
int create_check() {
	printf("Creating check...\n");
}

//function for caclulating all coast for products in check
int calculate_cost() {
	printf("Calculating cost...\n");
}

//function for exit programm then user pressing 6
int exit_programm() {
	printf("Exiting programm...\n");
}

	

int main() {
	define_products();
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
		}
	}
}