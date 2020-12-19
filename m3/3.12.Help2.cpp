#include <iostream>
using namespace std;

int main()
{
    cout << "Справка по инструкциям: " << endl
         << "  1. if" << endl
         << "  2. switch" << endl
         << "  3. for" << endl
         << "  4. while" << endl
         << "  5. do-while" << endl
         << "  6. break" << endl
         << "  7. continue" << endl
         << "  8. goto" << endl
         << "Выберите вариант справки (q для выхода): ";

    char choice;

    do {
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Синтаксис инструкции if:" << endl << endl;
                cout << "if (условие) {\n"
                    << "\tинструкция;\n"
                    << "} else {\n"
                    << "\tинструкция;\n"
                    << "}" 
                    << endl;
                break;

            case '2':
                cout << "Синтаксис интсрукции switch:" << endl << endl;
                cout << "switch(выражение) {\n"
                    << "\tcase константа:\n"
                    << "\t\tпоследовательность инструкций\n"
                    << "\t\tbreak;\n"
                    << "}" 
                    << endl;
                break;

            case '3':
                cout << "Синтаксис интсрукции for:" << endl << endl;
                cout << "for(инициализация; условие; инкремент) {\n"
                    << "\tинструкция;\n"
                    << "}" 
                    << endl;
                break;

            case '4':
                cout << "Синтаксис инструкции while:" << endl << endl;
                cout << "while(условие) {\n"
                    << "\tинструкция;\n"
                    << "}" 
                    << endl;
                break;

            case '5':
                cout << "Синтаксис инструкции do-while:" << endl << endl;
                cout << "do {\n"
                    << "\tинструкция;\n"
                    << "} while(условие);"
                    << endl;
                break;

            case '6':
                cout << "Инструкция break:" << endl << endl;
                cout << "break;" << endl;
                break;


            case '7':
                cout << "Инструкция continue:" << endl << endl;
                cout << "continue;" << endl;
                break;


            case '8':
                cout << "Инструкция goto:" << endl << endl;
                cout << "goto метка;" << endl;
                break;
        }
    } while ((choice < '1' || choice > '8') && choice != 'q');
    
    return 0;
}
