// Copyright 2021 Marina Usova

/*
Постановка задачи.
Реализована некоторая программа, работающая с матричными операциями.
Программист начал работать над ней и понял, что в ней много дублирования кода.
Он посмотрел свой код и не увидел проблем в самом коде. Чтобы исправить
проблему дублирования он решил вынести часть кода в функции.
Помогите ему в этом, а также допишите функционал, который он не успел.
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3
#define K 2
#define VECTOR_COORDINATES 3

//function for generating rand numbers
int matrix_num_gen(int max, int min) {
    int value = (max - min) * ((float)rand() / RAND_MAX) + min;
    return value;
}

//function for allocate memory for arrays
int** allocate_memory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));
    return matrix;
}

//function for printing matrix
void matrix_print(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//function for multiplying matrix by number
int** matrix_multiplying_number(int** matrix, int n, int m, int value) {
    int** res = NULL;
    res = allocate_memory(res, N, M);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix[i][j] * value;
        }
    }
    return res;
}

//function for generating matrix with random numbers
void values_for_matrix_gen(int** matrix, int n, int m, int max, int min) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = matrix_num_gen(max, min);
        }
    }
}

//function for freeing memory
void free_memory_for_arrays(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

//function for generating matrix
int** creating_matrix(int** matrix, int n, int m, int max, int min, char name) {
    matrix = allocate_memory(matrix, n, m);
    values_for_matrix_gen(matrix, n, m, max, min);
    printf("Matrix %c = \n", name);
    matrix_print(matrix, n, m);
    return matrix;
}

//function for allocating memory for vectors
int* allocate_memory_for_vector(int* matrixVector, int vc) {
    matrixVector = (int*)malloc(vc * sizeof(int*));
    return matrixVector;
}

//function for ading random numbers for vectors
void vector_by_rand_num(int** matrixVector, int vc, int max, int min) {
    for (int i = 0; i < vc; i++) {
        matrixVector[i] = matrix_num_gen(max, min);
    }
}

//function for printing vectors
void vector_print(int* matrixVector, int vc) {
    for (int i = 0; i < vc; i++) {
        printf("%d ", matrixVector[i]);
    }
    printf("\n");
}

//function for creating vectors
int* creating_vector(int* matrixVector, int vc, int max, int min, char name) {
    matrixVector = allocate_memory_for_vector(matrixVector, VECTOR_COORDINATES);
    vector_by_rand_num(matrixVector, VECTOR_COORDINATES, max, min);
    printf("Vector %c = \n", name);
    vector_print(matrixVector, vc);
    return matrixVector;
}

//function for multiplying vector by number
int* vector_multiply_number(int* matrixVector, int vc, int value) {
    int* res = NULL;
    res = allocate_memory_for_vector(res, VECTOR_COORDINATES);
    for (int i = 0; i < vc; i++) {
        res[i] = matrixVector[i] * value;
    }
    return res;
}

//main function
int main() {

    //------------------------------------------------------------------------

    int** matrix_A = NULL, ** matrix_B = NULL, ** result = NULL;
    int* vector_A = NULL, * vector_B = NULL, * resultV = NULL;
    int max = 4, min = 0, value = 0;

    srand(time(NULL));

    matrix_A = creating_matrix(matrix_A, N, M, max, min, 'A');
    matrix_B = creating_matrix(matrix_B, M, K, max, min, 'B');
    value = matrix_num_gen(max, min);

    result = allocate_memory(result, N, M);
    result = matrix_multiplying_number(matrix_A, N, M, value);
    printf("Matrix A x %d =\n", value);
    matrix_print(result, N, M);

    free_memory_for_arrays(result, N, M);
    
    //------------------------------------------------------------------------
    //transposition matrix
    //------------------------------------------------------------------------

    result = allocate_memory(result, M, N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix_A[j][i];
        }
    }

    printf("Matrix AT =\n");
    matrix_print(result, M, N);
    free_memory_for_arrays(result, M, N);

    //------------------------------------------------------------------------
    //multiplying two matrix
    //------------------------------------------------------------------------

    result = allocate_memory(result, N, K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            result[i][j] = 0;
            for (int k = 0; k < M; k++) {
                result[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }

    printf("Matrix A x B =\n");
    matrix_print(result, N, K);
    free_memory_for_arrays(result, N, K);

    //------------------------------------------------------------------------
    // addition two matrix
    //------------------------------------------------------------------------

    result = allocate_memory(result, N, M);

    if (N == K) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result[i][j] = matrix_A[i][j] + matrix_B[i][j];
            }
        }
        printf("Matrix A + B =\n");
        matrix_print(result, N, K);
    }
    else {
        printf("Matrices can't be added. \n\n");
    }

    free_memory_for_arrays(result, N, K);

    //------------------------------------------------------------------------
    // operations with vectors
    //------------------------------------------------------------------------

    vector_A = creating_vector(vector_A, VECTOR_COORDINATES, max, min, 'A');
    vector_B = creating_vector(vector_B, VECTOR_COORDINATES, max, min, 'B');

    //------------------------------------------------------------------------
    //multiplying vector by number
    //------------------------------------------------------------------------

    value = matrix_num_gen(max, min);

    resultV = allocate_memory_for_vector(resultV, VECTOR_COORDINATES);

    resultV = vector_multiply_number(vector_A, VECTOR_COORDINATES, value);
    printf("Vector A x %d\n", value);
    vector_print(resultV, VECTOR_COORDINATES);

    free(resultV);

    //------------------------------------------------------------------------
    // addition two vectors
    //------------------------------------------------------------------------

    resultV = allocate_memory_for_vector(resultV, VECTOR_COORDINATES);

    for (int i = 0; i < VECTOR_COORDINATES; i++) {
        resultV[i] = vector_A[i] + vector_B[i];
    }

    printf("Vector A + B =\n");
    vector_print(resultV, VECTOR_COORDINATES);

    free(resultV);

    //------------------------------------------------------------------------
    // multiplying two vectors
    //------------------------------------------------------------------------

    resultV = allocate_memory_for_vector(resultV, VECTOR_COORDINATES);

    if (VECTOR_COORDINATES < 3) {
        printf("Can't do vector A x vector B.");
    }
    else {
        for (int i = 0; i < VECTOR_COORDINATES; i++) {
            switch (i) {
            case 0:

                resultV[0] = vector_A[1] * vector_B[2] - vector_A[2] * vector_B[1];
                break;

            case 1:

                resultV[1] = -1 * (vector_A[0] * vector_B[2] - vector_A[2] * vector_B[0]);
                break;

            case 2:

                resultV[2] = vector_A[0] * vector_B[1] - vector_A[1] * vector_B[0];
                break;

            }
        }
        printf("Vector A x B =\n");
        vector_print(resultV, VECTOR_COORDINATES);
    }

    free(resultV);

    //------------------------------------------------------------------------
    // freeing memory
    //------------------------------------------------------------------------

    free_memory_for_arrays(matrix_A, N, M);
    free_memory_for_arrays(matrix_B, M, N);

    free(vector_A);
    free(vector_B);


    return 0;
}