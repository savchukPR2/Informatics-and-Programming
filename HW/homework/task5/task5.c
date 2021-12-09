#define _CRT_SECURE_NO_WARNINGS

//Inclusion of libraries that will be needed to solve the problem
#include <stdio.h>
#include "W:\Informatics-and-Programming\HW\homework\dirent-master\include\dirent.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

//Initialization of bool parameters
#ifndef __cplusplus
#define bool int
#define true 1
#define false 0
#endif

// Initialization of parameters that will be responsible for user selection
#define SORT_BY_INSERTS 0
#define SORT_BY_COUNT 1
#define HOARE_SORT 2
#define EXIT_PROGRAMM 3

#define SIZE 20

char files_in_dir[SIZE][40];
int count_of_files[SIZE][2];
int i = 0;
int sorted_mass[SIZE][2];
int hoare_perm;



int get_file_size(const char* file) {
	struct stat st;
	int full_size = 0;

	if (stat(file, &st) == 0) {

		if ((st.st_mode & S_IFMT) == S_IFDIR)
			return -1;

		else if ((st.st_mode & S_IFMT) == S_IFREG)
			return st.st_size;

		else
			return -2;
	}
}

void get_size_from_dir(char* path) {
	struct dirent* cur_file;
	DIR* dir;

	char full_file_path[200];

	dir = opendir(path);

	if (dir) {

		while ((cur_file = readdir(dir)) != NULL) {

			if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {

				strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
				int cur_file_size = get_file_size(full_file_path);

				if (cur_file_size >= 0) {

					strcpy(files_in_dir[i], cur_file->d_name);
					count_of_files[i][0] = i;
					count_of_files[i][1] = cur_file_size / 1024;
					i++;

				}
				else if (cur_file_size == -1)

					get_size_from_dir(full_file_path);
			}
		}

		closedir(dir);
	}
}

//User need to choose, what sort he want to use
int choose_by_user() {
	int num;

	printf("\nSelect sorting for program execution:\n 0 - Sort by Inserts\n 1 - Sort by Count\n 2 - Hoare Sort\n 3 - Exit Programm\n");

	while (true) {

		printf("Make your choose: ");
		scanf_s("%d", &num);

		if ((num >= SORT_BY_INSERTS) && (num <= EXIT_PROGRAMM))
			return num;

	}
}

//Sort by inserts
void insert_sort(int insert[20][2],int size) {

	int newElement, newElement1, location, num_of_perm = 0;

	for (int h = 1; h < size; h++)
	{
		newElement = insert[h][0];
		newElement1 = insert[h][1];
		location = h - 1;
		while (location >= 0 && insert[location][1] > newElement1)
		{
			insert[location + 1][1] = insert[location][1];
			insert[location + 1][0] = insert[location][0];
			location = location - 1;
			num_of_perm++;
		}
		insert[location + 1][0] = newElement;
		insert[location + 1][1] = newElement1;
	}

	printf("Sorted list of files by inerts is: \n File Name\t\t Size\n");
	for (int j = 0; j < SIZE; j++) {
		if (insert[j][1] > 0)
			printf("%s\t\t%d Kb\n", files_in_dir[insert[j][0]], insert[j][1]);
	}
	printf("Number of permutations - %d\n", num_of_perm);
}

//Sort by count
void insert_count(int insert[20][2], int size, int sorted_mass[20][2]) {

	int k, num_of_perm = 0;
	for (int i = 0; i < size; i++)
	{
		k = 0;
		for (int j = 0; j < size; j++)
		{
			if (insert[i][1] > insert[j][1]) {
				k++;
				num_of_perm++;
			}
		}
		sorted_mass[k][0] = insert[i][0];
		sorted_mass[k][1] = insert[i][1];
	}

	printf("Sorted list of files by count is: \n File Name\t\t Size\n");
	for (int j = 0; j < SIZE; j++) {
		if (sorted_mass[j][1] > 0)
			printf("%s\t\t%d Kb\n", files_in_dir[sorted_mass[j][0]], sorted_mass[j][1]);
	}
	printf("Number of permutations - %d\n", num_of_perm);

}

void qs(int s_arr[20][2], int first, int last)
{
	int i = first, j = last, x = s_arr[(first + last) / 2][1], tmp1, tmp2;

	do {
		while (s_arr[i][1] < x) i++;
		while (s_arr[j][1] > x) j--;

		if (i <= j) {
			if (s_arr[i][1] > s_arr[j][1]) {

				tmp1 = s_arr[i][1];
				s_arr[i][1] = s_arr[j][1];
				s_arr[j][1] = tmp1;

				tmp2 = s_arr[i][0];
				s_arr[i][0] = s_arr[j][0];
				s_arr[j][0] = tmp2;

				hoare_perm++;
			
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		qs(s_arr, i, last);
	if (first < j)
		qs(s_arr, first, j);
}


int main() {
	char path[200];
	time_t t0, t1;
	double extime;


	printf("Input path to dir: ");
	gets(path);
	get_size_from_dir(path);
	for (int j = 0; j < i; j++) {
		printf("%s\n", files_in_dir[j]);
	}

	/*printf("---------------------------------\n index\t size\n");

	for (int j = 0; j < i; j++) {
		printf("%d\t%d\n", count_of_files[j][0], count_of_files[j][1]);
	}*/

	switch (choose_by_user())
	{
	case SORT_BY_INSERTS:

		t0 = clock();
		insert_sort(count_of_files, SIZE);
		t1 = clock();
		extime = (double)(t1 - t0) / 1000;
		printf("\nTime of sort by Inserts is - %.7f", extime);
		break;

	case SORT_BY_COUNT:

		t0 = clock();
		insert_count(count_of_files, SIZE, sorted_mass);
		t1 = clock();
		extime = (double)(t1 - t0) / 1000;
		printf("\nTime of sort by Count is - %.7f", extime);
		break;

	case HOARE_SORT:

		t0 = clock();
		qs(count_of_files, 0, SIZE - 1);
		t1 = clock();
		extime = (double)(t1 - t0) / 1000;
		printf("\nTime of sort by Hoare is - %.7f\n", extime);

		for (int j = 0; j < SIZE; j++) {
			if (count_of_files[j][1] > 0)
				printf("%s\t\t%d Kb\n", files_in_dir[count_of_files[j][0]], count_of_files[j][1]);
		}
		printf("Number of permutation is - %d\n", hoare_perm);
		break;

	case EXIT_PROGRAMM:
		_Exit(EXIT_SUCCESS);
		break;
	}

	return 0;
}

