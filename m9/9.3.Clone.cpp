#include <iostream>
using namespace std;

class MyClass {
    int val;
    int copyNumber;
    public:
        MyClass(int i) {
            val = i;
            copyNumber = 0;
            cout << "Внутри обычного конструктора.\n";
        }
        
        MyClass(const MyClass &o) {
            val = o.val;
            copyNumber = o.copyNumber + 1;
        }

        ~MyClass() {
            if (copyNumber == 0) {
                cout << "Разрушение оригинального объекта.\n";
            } else {
                cout << "Разрушение копии " << copyNumber << ".\n";
            }
        }

        int getVal() { return val; }
};

void display(MyClass o) 
{
    cout << o.getVal() << "\n";
} 

int main()
{
    MyClass a(10);

    display(a);

    return 0;
}