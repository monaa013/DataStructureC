#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to print the matrix
void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to insert a value into the matrix
void insertValue(int matrix[ROWS][COLS], int row, int col, int value) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        matrix[row][col] = value;
        printf("Value %d inserted at position in matrix 1 (%d, %d).\n", value, row, col);
    } else {
        printf("Invalid position for insertion.\n");
    }
}

// Function to delete a value from the matrix
void deleteValue(int matrix[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        matrix[row][col] = 0;  // Assuming 0 represents no quality value
        printf("Value deleted at position in matrix 1 (%d, %d).\n", row, col);
    } else {
        printf("Invalid position for deletion.\n");
    }
}

// Function for linear search in the matrix
int linearSearch(int matrix[ROWS][COLS], int target) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == target) {
                printf("Value %d found at position in matrix 1 (%d, %d).\n", target, i, j);
                return 1;  // Value found
            }
        }
    }
    printf("Value %d not found in the matrix.\n", target);
    return 0;  // Value not found
}

// Function to calculate the average quality of chocolates
float calculateAverageQuality(int matrix[ROWS][COLS]) {
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
    }
    return (float)sum / (ROWS * COLS);
}

// Function for matrix addition
void matrixAddition(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function for matrix multiplication
void matrixMultiplication(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int chocolateMatrix1[ROWS][COLS];
    int chocolateMatrix2[ROWS][COLS];
    int resultMatrix[ROWS][COLS];

    // User input for matrix1 values
    printf("Enter the values for the 3x3 Chocolate Price (Matrix 1):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Enter value at position (%d, %d): ", i, j);
            scanf("%d", &chocolateMatrix1[i][j]);
        }
    }

    // User input for matrix2 values
    printf("Enter the values for the 3x3 Chocolate Quantity (Matrix 2):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Enter value at position (%d, %d): ", i, j);
            scanf("%d", &chocolateMatrix2[i][j]);
        }
    }

    printf("Chocolate Price (Matrix 1):\n");
    printMatrix(chocolateMatrix1);

    printf("Chocolate Price (Matrix 2):\n");
    printMatrix(chocolateMatrix2);

    // Matrix addition
    matrixAddition(chocolateMatrix1, chocolateMatrix2, resultMatrix);
    printf("Matrix Addition Result:\n");
    printMatrix(resultMatrix);

    // Matrix multiplication
    matrixMultiplication(chocolateMatrix1, chocolateMatrix2, resultMatrix);
    printf("Matrix Multiplication Result:\n");
    printMatrix(resultMatrix);

    // User input for insertion
    int insertRow, insertCol, valueToInsert;
    printf("Enter position for insertion in matrix 1 (row col): ");
    scanf("%d %d", &insertRow, &insertCol);
    printf("Enter value for insertion in matrix 1: ");
    scanf("%d", &valueToInsert);
    insertValue(chocolateMatrix1, insertRow, insertCol, valueToInsert);

    // User input for deletion
    int deleteRow, deleteCol;
    printf("Enter position for deletion in matrix 1 (row col): ");
    scanf("%d %d", &deleteRow, &deleteCol);
    deleteValue(chocolateMatrix1, deleteRow, deleteCol);

    printf("Updated Chocolate matrix 1:\n");
    printMatrix(chocolateMatrix1);

    // User input for linear search
    int targetValue;
    printf("Enter value to search from matrix 1: ");
    scanf("%d", &targetValue);
    linearSearch(chocolateMatrix1, targetValue);

    // Calculate and print average quality
    float averageQuality = calculateAverageQuality(chocolateMatrix1);
    printf("Average Quality of Chocolates: %.2f\n", averageQuality);

    return 0;
}
