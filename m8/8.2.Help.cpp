#include <iostream>
using namespace std;

class Help {
    public:
        void helpon(char what);
        void showmenu();
        bool isvalid(char ch);
};

void Help::helpon(char what) {
   switch (what) {
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
                 << "}" << endl;
                 ;
            break;

        default:
            cout << "Такого варианта нет." << endl;
            break;
    }
}

void Help::showmenu() {
 cout << "Справка по инструкциям: " << endl
         << "  1. if" << endl
         << "  2. switch" << endl
         << "Выберите вариант справки: ";
}

bool Help::isvalid(char ch) {
    return (ch >= 1 && ch < 3) || ch == 'q';
}

int main()
{
    Help h;
    char what;

    h.showmenu();
    do {
        cin >> what; //what << cin;
        if (what == 'q') break;
        h.helpon(what);
    } while(!h.isvalid(what));

    return 0;
}