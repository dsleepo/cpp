#include <iostream>


void printNumber(int number) {
    std::cout << number;
    int k{ 1 };

    if (number < 10) {
        k = 4;
    } else if (number < 100) {
        k = 3;
    } else if (number < 1000) {
        k = 2;
    }

    for (int l = 0; l < k; l++) {
        std::cout << " ";
    }
}

void task1() 
{
    int x;
    double y;
    char c;

    int *pi;
    double *pf;
    char *pc;

    std::cout << "Введите значения (целое, вещественное, символ): ";
    std::cin >> x >> y >> c;

    pi = &x;
    pf = &y;
    pc = &c;

    *pi = *pi * 2;
    *pf = *pf * 2;
    *pc = *pc * 2;

    std::cout << *pi << " " << *pf << " " << *pc << "\n"; 
    std::cout << pi  << " " << pf  << " " << (void *)pc << "\n";
    std::cout << &pi << " " << &pf << " " << &pc << "\n"; 
}


void printArray(int length, int *items) {
    for (int i = 0; i < length; i++) {
        std::cout << items[i] << " ";   
    }
    std::cout << "\n";
}

void maxHope(int length, int *items) {
    
    int maxStart = 0, maxEnd = 0;
    int start = 0, end = 0;
    for (int i = 1; i < length; i++) {
        if (items[i] > items[start] && items[i] > items[i-1]) {
            end = i;

            if (items[end] - items[start] > items[maxEnd] - items[maxStart]) {
                maxStart = start;
                maxEnd = end;
            } 
        } else {
            start = end = i;
        }
    }

    int maxLength = maxEnd > 0 ? maxEnd - maxStart + 1 : 0;
    int maxDifference = items[maxEnd] - items[maxStart];
    std::cout << "max difference: " << maxDifference << "\n";
    std::cout << "max length: " << maxLength << "\n";
}

void task2()
{
    int n = 30;
    int items[n];
    for (int i = 0; i < n; i++) {
        items[i] = rand() % 100;
    }
    printArray(n, items);

    maxHope(n, items);
}

const int n = 20;

void task3()
{
    int items[n];
    int c[n][2] = {0};
    for (int i = 0; i < n; i++) {
        items[i] = rand() % 20;
    }
    printArray(n, items);
    
    for (int i = 0; i < n; i++) {
        c[items[i]][0] = items[i];
        c[items[i]][1] += 1;
    }

    for (int i = 0; i < n; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (c[j][1] > c[max][1]) {
                max = j;
            }
        }
        std::swap(c[i], c[max]);
    }

    for (int i = 0; i < n; i++) {
        if (c[i][1] == 0) break;
        std::cout << c[i][0] << " " << c[i][1] << "\n";
    }
}

void task4() {
    const int max = 1000;
    int simpleNumbers[max] = {0};

    int n = -1;
    for (int i = 2; n < 999; ++i) {
        bool isSimple = true;
        
        for (int j = 2; j < (i / 2); j++) {
            if (i % j == 0) {
                isSimple = false;
                break;
            }
        }
    
        if (!isSimple) {
            continue;
        }

        simpleNumbers[++n] = i;
        printNumber(i);

        if (n > 0 && ((n + 1) % 20 == 0)) {
            std::cout << "\n";
        }
    }
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

        case 4:
            task4();
            break;

        default:
            std::cout << "Wrong task number.\n";
            break;
    }

    return 0;
}
