#include <iostream>
using namespace std;

int main()
{
    cout << "Справка по инструкциям: " << endl
         << "  1. if" << endl
         << "  2. switch" << endl
         << "Выберите вариант справки: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Синтаксис инструкции if:" << endl << endl;
            cout << "if (условие) {\n"
                 << "\tинструкция;\n"
                 << "} else {\n"
                 << "\tинструкция;\n"
                 << "}" 
                 << endl;
            break;

        case 2:
            cout << "Синтаксис интсрукции switch:" << endl << endl;
            cout << "switch(выражение) {\n"
                 << "\tcase константа:\n"
                 << "\t\tпоследовательность инструкций\n"
                 << "\t\tbreak;\n"
                 << "}" << endl;
                 ;
            break;

        default:
            cout << "Такого варианта нет." << endl;
            break;
    }

    return 0;
}
