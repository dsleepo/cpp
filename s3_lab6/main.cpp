#include <iostream>
#include <cmath>

void printMatrix(unsigned int n, double** matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

class Matrix {
    int n = 5;
    double **items;

    public:
        Matrix(int n) {
            this->n = n;
            items = new double *[n];
            for (int i = 0; i < n; i++) {
                items[i] = new double[n];
            }

            for (unsigned int i = 0; i < n; i++) {
                for (unsigned int j = 0; j < n; j++) {
                    double value{ 0 };
                    std::cout << "a[" << i << "][" <<  j << "] = ";
                    std::cin >> value;
                    items[i][j] = value;
                }
            }
        }

        Matrix() {
            items = new double*[n];
            for (int i = 0; i < n; i++) {
                items[i] = new double[n];
            }

            for (unsigned int i = 0; i < n; i++) {
                for (unsigned int j = 0; j < n; j++) {
                    items[i][j] = 1. / (i + j +1);
                }
            }
        }

        Matrix(bool isOne, unsigned int n = 2) {
            this->n = n;

            items = new double*[n];
            for (unsigned int i = 0; i < n; i++) {
                items[i] = new double[n];
            }

            for (unsigned int i = 0; i < n; i++) {
                for (unsigned int j = 0; j < n; j++) {
                    items[i][j] = 1;
                }
            }
        }

        ~Matrix() {
            for (unsigned int i = 0; i < n; i++) {
                delete[] items[i];
            }
            delete[] items;
        }

        double min() {
            double min = items[0][0];

            for (unsigned int i = 0; i < n; i++) {
                for (unsigned int j = 0; j < n; j++) {
                    if (items[i][j] < min) {
                        min = items[i][j];
                    }
                }
            }

            return min;
        }

        double max() {
            double max = items[0][0];

            for (unsigned int i = 0; i < n; i++) {
                for (unsigned int j = 0; j < n; j++) {
                    if (items[i][j] > max) {
                        max = items[i][j];
                    }
                }
            }

            return max;
        }

        double spur() {
            double sum = 0;

            for (unsigned int i = 0; i < n; i++) {
                sum += items[i][i];
            }

            return sum;
        }

        void swap(int i, int j) {
            if (!(i >= 0 && i <= n) || !(j >= 0 && j <= n)) {
                return;
            }
            for (unsigned int k = 0; k < n; k++) {
                std::swap(items[i][k], items[j][k]);
            }
        }

        void print() {
            printMatrix(n, items);
        }

        double determinant() {
            return determinantImplementation(n, items);
        }

        double determinantImplementation(int n, double** matrix) {
            if (n == 1) {
                return matrix[0][0];
            }
            
            if (n == 2) {
                return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
            }

            int minorN = n - 1;
            double **minor = new double*[minorN];
            for (int j = 0; j < minorN; j++) {
                minor[j] = new double[minorN];
            }

            double determinant = 0;
            
            int row = 0;
            for (int col = 0; col < n; col++) {
                
                int minorRow = -1;
                for (int i = 0; i < n; i++) {
                    if (row == i) continue;
                    ++minorRow;

                    int minorCol = -1;
                    for (int j = 0; j < n; j++) {
                        if (col == j) continue;
                        ++minorCol;
                        minor[minorRow][minorCol] = matrix[i][j];
                    }
                }

                determinant += pow(-1, col) * matrix[row][col] * determinantImplementation(minorN, minor);
            }

            return determinant;
        }
};

void task1() {

    Matrix m1{ 3 };
    m1.print();
    std::cout << "min: " << m1.min() << std::endl;
    std::cout << "max: " << m1.max() << std::endl;
    std::cout << "spur: " << m1.spur() << std::endl;
    std::cout << "det: " << m1.determinant() << std::endl;
}

void task2() {
    Matrix m1;
    m1.print();
    std::cout << "min: " << m1.min() << std::endl;
    std::cout << "max: " << m1.max() << std::endl;
    std::cout << "spur: " << m1.spur() << std::endl;
    std::cout << "det: " << m1.determinant() << std::endl;
}

void task3() {
    Matrix m1(true);
    m1.print();
    std::cout << "min: " << m1.min() << std::endl;
    std::cout << "max: " << m1.max() << std::endl;
    std::cout << "spur: " << m1.spur() << std::endl;
    std::cout << "det: " << m1.determinant() << std::endl;
}

int main()
{
    int taskNumber = 0;
    std::cout << "Enter task number: ";
    std::cin >> taskNumber;

    switch (taskNumber) {
        case 1:
            task1();
            break;
        
        case 2:
            task2();
            break;

        case 3:
            task3();
            break;

        default:
            std::cout << "Wrong task number.\n";
            break;
    }

    return 0;
}
