#include <iostream>

const int MaxSize = 100;

class Set {
    int len;
    char members[MaxSize];

    int find(char ch);

public:
    Set() { len = 0; }

    int getLength() { return len; }
    void show();
    bool isMember(char ch);

    Set operator+(char ch);
    Set operator-(char ch);

    Set operator+(Set ob2);
    Set operator-(Set ob2);

    bool operator>(Set ob2);
    bool operator<(Set ob2);

    Set operator&(Set ob2);
    Set operator|(Set ob2);
};

int Set::find(char ch) {
    for (int i = 0; i < len; i++) {
        if (members[i] == ch) {
            return i;
        }
    }
    return -1;
}

void Set::show() {
    std::cout << "{ ";
    for (int i = 0; i < len; i++) {
        std::cout << members[i] << " ";    
    }
    std::cout << "}\n";
}

bool Set::isMember(char ch) {
    return find(ch) != -1;
}

Set Set::operator+(char ch) {
    Set temp = *this;

    if (len == MaxSize) {
        std::cout << "Множество заполнено.\n";
        return *this;
    }

    if (find(ch) == -1) {
        temp.members[temp.len] = ch;
        temp.len++;
    }

    return temp;
}

Set Set::operator-(char ch) {
    Set temp;
    int pos = find(ch);

    for (int j = 0; j < len; j++) {
        if (j != pos) temp = temp + members[j];
    }

    return temp;
}

Set Set::operator+(Set ob2) {
    Set temp = *this;

    for (int i = 0; i < ob2.len; i++) {
        temp = temp + ob2.members[i];
    }

    return temp;
}

Set Set::operator-(Set ob2) {
    Set temp = *this;

    for (int i = 0; i < ob2.len; i++) {
        temp = temp - ob2.members[i];
    }

    return temp;
}

bool Set::operator>(Set ob2) {
    for (int i = 0; i < ob2.len; i++) {
        if (this->find(ob2.members[i]) == -1) {
            return false;
        }
    }
    return true;
}

bool Set::operator<(Set ob2) {
    for (int i = 0; i < this->len; i++) {
        if (ob2.find(this->members[i]) == -1) {
            return false;
        }
    }
    return true;
}

Set Set::operator&(Set ob2) {
    Set temp;

    for (int i = 0; i < this->len; i++) {
        if (ob2.find(this->members[i]) != -1) {
            temp = temp + this->members[i];
        }
    }

    return temp;
}

Set Set::operator|(Set ob2) {
    Set temp;

    for (int i = 0; i < this->len; i++) {
        if (ob2.find(this->members[i]) == -1) {
            temp = temp + this->members[i];
        }
    }

    for (int i = 0; i < ob2.len; i++) {
        if (this->find(ob2.members[i]) == -1) {
            temp = temp + ob2.members[i];
        }
    }

    return temp;
}

int main()
{
    Set s1;
    Set s2;
    Set s3;

    s1 = s1 + 'A';
    s1 = s1 + 'B';
    s1 = s1 + 'C';

    std::cout << "Множество s1 после добавления символов A B C: ";
    s1.show();

    std::cout << "\n";
    std::cout << "Тестирование членства с помощью функции isMember().\n";

    if (s1.isMember('B')) {
        std::cout << "B - член множества s1.\n";
    } else {
        std::cout << "B - не член множества s1.\n";
    }

    if (s1.isMember('T')) {
        std::cout << "T - член множества s1.\n";
    } else {
        std::cout << "T - не член множества s1.\n";
    }
    std::cout << "\n";

    s1 = s1 - 'B';
    std::cout << "Множество s1 после s1 = s1 - 'B': ";
    s1.show();

    s1 = s1 - 'A';
    std::cout << "Множество s1 после s1 = s1 - 'A': ";
    s1.show();

    s1 = s1 - 'C';
    std::cout << "Множество s1 после s1 = s1 - 'C': ";
    s1.show();
    std::cout << "\n";

    s1 = s1 + 'A';
    s1 = s1 + 'B';
    s1 = s1 + 'C';
    std::cout << "Множество s1 после добавления A B C: ";
    s1.show();
    std::cout << "\n";

    s2 = s2 + 'A';
    s2 = s2 + 'X';
    s2 = s2 + 'W';
    std::cout << "Множество s2 после добавления A X W: ";    
    s2.show();
    std::cout << "\n";

    s3 = s1 + s2;
    std::cout << "Множество s3 после s3 = s1 + s2: ";
    s3.show();
    std::cout << "\n";

    s3 = s3 - s1;
    std::cout << "Множество s3 после s3 = s3 - s1: ";
    s3.show();
    std::cout << "\n";

    s2 = s2 - s2;
    std::cout << "Множество s2 после s2 = s2 - s2: ";
    s2.show();
    std::cout << "\n";
    
    s2 = s2 + 'C';
    s2 = s2 + 'B';
    s2 = s2 + 'A';

    std::cout << "Множество s2 после добавления C B A: ";
    s2.show();

    Set s4, s5;
    s4 = s4 + 'A' + 'B' + 'C';
    s5 = s5 + 'A' + 'B';

    s4.show();
    s5.show();

    bool isSubset1 = s4 < s5;
    bool isSubset2 = s5 < s4;
    std::cout << "subset " << isSubset1 << " " << isSubset2 << "\n\n";

    bool isSuperset1 = s4 > s5;
    bool isSuperset2 = s5 > s4;
    std::cout << "superset " << isSuperset1 << " " << isSuperset2 << "\n\n";

    Set and1 = s4 & s5;
    Set and2 = s5 & s4;
    std::cout << "and ";
    and1.show();
    and2.show();
    std::cout << "\n";

    Set xor1 = s4 | s5;
    Set xor2 = s5 | s4; 
    std::cout << "xor ";
    xor1.show();
    xor2.show();
    std::cout << "\n";

    return 0;
}
