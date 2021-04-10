#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int task1()
{
    cout << "1" << endl;
    short int shortIntVar;
    unsigned short int shortIntVarUnsigned;
    cout << "Size of short int: " << sizeof(shortIntVar) << ", unsigned: " << sizeof(shortIntVarUnsigned) << endl;

    int intVar;
    unsigned int intVarUnsigned;
    cout << "Size of int: " << sizeof(intVar) << ", unsigned: " << sizeof(intVarUnsigned) << endl;

    long int longInt;
    unsigned long int longIntUnsigned;
    cout << "Size of long int: " << sizeof(longInt) << ", unsigned: " << sizeof(longIntUnsigned) << endl;

    long long int longLongInt;
    unsigned long long int longLongIntUnsigned;
    cout << "Size of long long int: " << sizeof(longLongInt) << ", unsigned: " << sizeof(longLongIntUnsigned) << endl;

    float floatVar;
    cout << "Size of float: " << sizeof(floatVar) << endl;

    // invalid combination of type specifiers
    // long float longFloatVar;
    // cout << "Size of long float: " << sizeof(longFloatVar) << endl;

    double doubleVar;
    cout << "Size of double: " << sizeof(doubleVar) << endl;

    long double longDoubleVar;
    cout << "Size of long double: " << sizeof(longDoubleVar) << endl;

    bool boolVar;
    cout << "Size of bool: " << sizeof(boolVar) << endl;

    char charVar;
    unsigned char charVarUnsigned;
    cout << "Size of char: " << sizeof(charVar) << ", unsigned: " << sizeof(charVarUnsigned) <<endl;

    wchar_t wcharVar;
    cout << "Size of wchar_t: " << sizeof(wcharVar) << endl << endl;

    // 1. int и unsigned int   - нет
    // 2. double и long double - да
    // 3. char и unsigned char - нет 

    return 0;
}

int task2()
{
    cout << "2" << endl;
    float floatVar1 = -1.1, floatVar2 = -1.5, floatVar3 = -1.9, floatVar4 = 1.1, floatVar5 = 1.5,floatVar6 = 1.9;
    int intVar1 = floatVar1, 
        intVar2 = floatVar2, 
        intVar3 = floatVar3, 
        intVar4 = floatVar4, 
        intVar5 = floatVar5, 
        intVar6 = floatVar6;

    cout << "float->int " << floatVar1 << " явное: " << int(floatVar1) << ", неявное: " << intVar1 << endl; // -1
    cout << "float->int " << floatVar2 << " явное: " << int(floatVar2) << ", неявное: " << intVar2 << endl; // -1
    cout << "float->int " << floatVar3 << " явное: " << int(floatVar3) << ", неявное: " << intVar3 << endl; // -1
    cout << "float->int " << floatVar4 << " явное: " << int(floatVar4) << ", неявное: " << intVar4 << endl; //  1
    cout << "float->int " << floatVar5 << " явное: " << int(floatVar5) << ", неявное: " << intVar5 << endl; //  1
    cout << "float->int " << floatVar6 << " явное: " << int(floatVar6) << ", неявное: " << intVar6 << endl; //  1


    float doubleVar1 = -1.1, doubleVar2 = -1.5, doubleVar3 = -1.9, doubleVar4 = 1.1, doubleVar5 = 1.5, doubleVar6 = 1.9;
    int intVar1d = doubleVar1, 
        intVar2d = doubleVar2, 
        intVar3d = doubleVar3, 
        intVar4d = doubleVar4, 
        intVar5d = doubleVar5, 
        intVar6d = doubleVar6;

    cout << "double->int " << doubleVar1 << " явное: " << int(doubleVar1) << ", неявное: " << intVar1d << endl; // -1
    cout << "double->int " << doubleVar2 << " явное: " << int(doubleVar2) << ", неявное: " << intVar2d << endl; // -1
    cout << "double->int " << doubleVar3 << " явное: " << int(doubleVar3) << ", неявное: " << intVar3d << endl; // -1
    cout << "double->int " << doubleVar4 << " явное: " << int(doubleVar4) << ", неявное: " << intVar4d << endl; //  1
    cout << "double->int " << doubleVar5 << " явное: " << int(doubleVar5) << ", неявное: " << intVar5d << endl; //  1
    cout << "double->int " << doubleVar6 << " явное: " << int(doubleVar6) << ", неявное: " << intVar6d << endl; //  1  


    bool boolVar1 = true, boolVar2 = false;
    int intVar1b = boolVar1, intVar2b = boolVar2;

    cout << "bool->int " << boolVar1 << " явное: " << int(boolVar1) << ", неявное: " << intVar1b << endl; // 1
    cout << "bool->int " << boolVar2 << " явное: " << int(boolVar2) << ", неявное: " << intVar2b << endl; // 0

    int intVar1i = 5;
    bool boolVar1i = intVar1i;

    cout << "int->bool " << intVar1i << " явное: " << bool(intVar1i) << ", неявное: " << boolVar1i << endl << endl; // 1


    return 0;
}

int task3()
{
    cout << "3" << endl;
    cout << "max char: " << SCHAR_MAX << endl;               // 127
    cout << "max unsigned char: " << UCHAR_MAX << endl;      // 255
    cout << "max short int: " << SHRT_MAX << endl;           // 32767
    cout << "max unsigned short int: " << USHRT_MAX << endl; // 65535

    // a
    unsigned char uc;
    uc = 250;
    uc += 10;
    cout << "unsigned char 250 + 10: " << int(uc) << endl; // 4

    // b
    char c = 100;
    c += 30;
    cout << "char 100 + 30: " << int(c) << endl; // -126
    
    short int si = SHRT_MAX + 1;
    cout << "short int " << SHRT_MAX << " + 1: " << si << endl << endl; // -32768

    return 0;
}

int task4()
{
    unsigned char uc;
    char c;
    uc = 150;
    c = uc;
    cout << endl << "4 " << endl
        << "4_a " << c << " " << int(c) << endl; // -106

    unsigned char uc1;
    char c1;
    c1 = -1;
    uc1 = c1;

    cout << "   " << c1  << " " << int(c1) << endl; // -1
    cout << "   " << uc1 << " " << int(uc1) << endl; //255

    unsigned long int uli1 = -1;
    cout << "4_b " << uli1 << endl;

    return 0;
}

int task5_a()
{
    unsigned long int ui;
    long int i;
    float f;

    i = -1;
    ui = i;
    f = ui;

    cout << endl << "5_a " << endl << f << " " 
        << (f + 1099511693312) << " " 
        << (f + 1099511693313) << endl << endl; // 1.844674627273281e+19 

    return 0;
}

int task5_b()
{
    unsigned long int ui;
    long int i;
    double d;

    i = -1;
    ui = i;
    d = ui;
    
    cout << endl<< "5_b " << endl << d << " " 
        << (d + 2048) << " " 
        << (d + 2049) << endl << endl; // 1.844674407370956e+19

    return 0;
}

int task5_cd()
{
    float f1 = 1.0;
    cout << "5_cd" << endl << f1 << " " 
        << (f1 + 0.000000059F) << " " 
        << (f1 + 0.00000006F) << endl; // 1.00000011920928955078125

    float f2 = 10.0;
    cout << f2 << " " 
        << (f2 + 0.000000476F) << " " 
        << (f2 + 0.000000477F) << endl << endl; // 10.00000095367431640625

    return 0;
}

int main()
{
    std::cout << std::setprecision(32);

    task1();

    task2();

    task3();

    task4();

    task5_a();

    task5_b();

    task5_cd();

    return 0;
}

