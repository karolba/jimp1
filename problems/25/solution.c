// author: Karol Baraniecki

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define rows 2
#define columns 2

static void assert_read(bool b) {
    if(!b) {
        puts("End of input!");
        exit(0);
    }
}

static double readDouble(void) {
    double d;
    assert_read(scanf("%*[^0-9]") == 0);
    assert_read(scanf("%lf", &d) == 1);
    return d;
}

static void readMatrix(double matrix[rows][columns]) {
    matrix[0][0] = readDouble();
    matrix[0][1] = readDouble();
    matrix[1][0] = readDouble();
    matrix[1][1] = readDouble();
}

static void printMatrix(const char *name, double matrix[rows][columns]) {
    printf("Matrix %s:\n", name);
    printf("%.1lf %.1lf\n", matrix[0][0], matrix[0][1]);
    printf("%.1lf %.1lf\n", matrix[1][0], matrix[1][1]);
}

static void addMatrices(double m1[rows][columns], double m2[rows][columns], double result[rows][columns]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

static void multiplyMatrices(double m1[rows][columns], double m2[rows][columns], double result[rows][columns]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            result[i][j] = 0;
            for(int k = 0; k < columns; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main(void) {
    double matrix1[rows][columns], matrix2[rows][columns], resultMatrix[rows][columns];
    readMatrix(matrix1);
    printMatrix("matrix1", matrix1);

    readMatrix(matrix2);
    printMatrix("matrix2", matrix2);

    addMatrices(matrix1, matrix2, resultMatrix);
    printMatrix("matrix1+matrix2", resultMatrix);

    multiplyMatrices(matrix1, matrix2, resultMatrix);
    printMatrix("matrix1*matrix2", resultMatrix);
    return 0;
}
