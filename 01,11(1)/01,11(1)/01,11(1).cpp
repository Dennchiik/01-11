#include <iostream>

void addColumn(int** matrix, int rows, int columns, int columnIndex, int* newColumn) {
    if (columnIndex < 0 || columnIndex > columns) {
        std::cout << "Неверный индекс столбца" << std::endl;
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = columns; j > columnIndex; j--) {
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][columnIndex] = newColumn[i];
    }
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

    int newColumn[] = { 10, 11, 12 };

    addColumn(matrix, rows, columns, 1, newColumn);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns + 1; j++) {
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
