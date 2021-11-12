#include <iostream>
using namespace std;

class MyClass {
    int val;
    int copynumber;
    public:
        MyClass(int i) {
            val = i;
            copynumber = 0;
            cout << "Внутри конструктора " << copynumber << '\n';
        }

        MyClass(const MyClass &o) {
            copynumber++;
            cout << "Внутри конструктора копии " << copynumber << '\n';
        }

        ~MyClass() {
            cout << "Разрушение объекта " << copynumber << "\n";
        }

        int getVal() { return val; }

        MyClass mkBigger() {
            MyClass o(val*2);
            return o;
        }  
};

void display(MyClass o) 
{
    cout << o.getVal() << "\n";
}

int main()
{
    cout << "Перез созданием объекта a.\n";
    MyClass a(10);
    cout << "После создание объекта a.\n\n";

    cout << "Перед вызовом функции display().\n";
    display(a);
    cout << "После возвращения из функции dislay().\n\n";

    cout << "Перед вызовом функции mkBigger().\n";
    a = a.mkBigger();
    cout << "После возвращения из функции mkBigger().\n\n";

    cout << "Перед вторым вызовом функции display().\n";
    display(a);
    cout << "После вторым возвращения из функции display().\n\n";

    return 0;
}