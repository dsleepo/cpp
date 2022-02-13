#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void read_file_using_operator_bitwise_right_shift()
{
    ifstream file("example.txt", ifstream::in);
    if (!file.is_open()) 
    {
        cerr << "Failed to open file." << endl;
        return;
    }

    string line;
    while (!file.eof()) 
    {
        file >> line;
        cout << line << endl;   
    }

    file.close();
}

void read_file_using_get()
{
    ifstream file("example.txt", ifstream::in);
    if (!file.is_open())
    {
        cerr << "Failed to open file." << endl;
        return;
    }

    char ch;
    while (file)
    {
        ch = file.get();
        if (file.eof()){
            break;
        }
        cout << ch;
    }

    file.close();
    
}

void read_file_using_char_getline()
{
    ifstream file("example.txt", ifstream::in);
    if (!file.is_open())
    {
        cerr << "Failed to open file." << endl;
        return;
    }

    const int lineSize{ 50 };
    char line[lineSize];
    while (file.getline(line, lineSize))
    {
        cout << line << "\n";
    }

    file.close();    
}

void read_file_using_string_getline()
{
    ifstream file("example.txt", ifstream::in);
    if (!file.is_open())
    {
        cerr << "Failed to open file.";
        return;
    }

    string line{""};
    while (getline(file, line))
    {
        cout << line << "\n";
    }

    file.close();
}

void write_file_using_operator_bitwise_lest_shift()
{
    ofstream file("example2.txt", ofstream::app);
    if (!file.is_open())
    {
        cerr << "Failed to open file.";
        return;
    }

    file << "Example string" << '\n';

    file.close();
}

void write_file_using_put()
{
    ofstream file("example2.txt", ofstream::app);
    if (!file.is_open())
    {
        cerr << "Failed to open file.";
        return;
    }

    file.put('a');
    file.put('\n');

    file.close();
}

void write_file_using_write()
{
    ofstream file("example2.txt", ofstream::app);
    if (!file.is_open())
    {
        cerr << "Failed to open file.";
        return;
    }

    char line[]{"Example string 2\n"};
    file.write(line, sizeof(line) - 1);
}

void read_from_cin_and_write_to_file()
{
    ofstream file("example2.txt", ofstream::app);
    if (!file.is_open())
    {
        cerr << "Failed to open file.";
        return;
    }

    char line[20];
    cout << "Type something: ";
    cin >> line;
    file << line;
    file << "\n";

    file.close();
}

struct Point 
{
    int x, y, z;

    Point()
    {
        x = y = z = 0;
    }

    Point(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void print()
    {
        cout << "x= " << x << " y=" << y << " z=" << z << endl;
    }
};

void write_and_read_object()
{
    Point p(2, 4, 6);
    p.print();

    ofstream fout("point.txt", ofstream::app);
    if (!fout.is_open())
    {
        cerr << "Failed to open file.";
        return;
    }

    fout.write((char*) &p, sizeof(Point));
    fout.close();

    ifstream fin("point.txt", ofstream::in);
    if (!fin.is_open())
    {
        cerr << "Failed to open file.";
        return;
    }

    Point p2;
    while (fin.read((char*) &p2, sizeof(Point)))
    {
        p2.print();
    }   
}

void read_and_write_using_fstream()
{
    fstream file("example2.txt", fstream::in | fstream::out);
    if (!file.is_open())
    {
        cerr << "Failed to open file.";
        return;
    }

    string line{ "Test string" };
    file << line;
    cout << file.tellg() << endl; // 11 
    
    cout << file.tellg() << " " << file.eof() << endl;
    getline(file, line);
    file.clear();
    cout << line << endl; // <empty>


    file.seekg(0, fstream::beg);
    getline(file, line);
    cout << line << endl; // Test string
    file.clear();

    file.seekg(-6, fstream::end);
    file << "string2";
}

int main()
{
    // read_file_using_operator_bitwise_right_shift();
    // read_file_using_get();
    // read_file_using_char_getline();
    // read_file_using_string_getline();

    // write_file_using_operator_bitwise_lest_shift();
    // write_file_using_put();
    // write_file_using_write();

    // read_from_cin_and_write_to_file();
    // write_and_read_object();

    read_and_write_using_fstream();

    return 0;
}