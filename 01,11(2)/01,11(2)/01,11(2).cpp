#include <iostream>

void deleteColumn(int** matrix, int& rows, int& columns, int columnIndex) {
    if (columnIndex < 0 || columnIndex >= columns) {
        std::cout << "Неверный индекс столбца" << std::endl;
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = columnIndex; j < columns - 1; j++) {
            matrix[i][j] = matrix[i][j + 1];
        }
    }
    for (int i = 0; i < rows; i++) {
        int* tempRow = new int[columns - 1];
        for (int j = 0; j < columns - 1; j++) {
            tempRow[j] = matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i] = tempRow;
    }
    columns--;
}

int main() {
    int rows = 3;
    int columns = 3;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = i * columns + j + 1;
        }
    }

    deleteColumn(matrix, rows, columns, 1);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
