#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

const int W = 60;
const int H = 11;

const char DEAD = ' ';
const char ALIVE = '1';

void loadCellsFromFile(string path, char *cells) 
{
    ifstream file(path);
    
    for (int i = 0, j = W * H; i < j; ++i) 
    {
        cells[i] = DEAD;
    }

    if (!file.is_open())
    {
        cerr << "Файл не окрывается." << endl;
        return;
    }

    string line;
    for (int k = 0; getline(file, line); k++)
    {
        for (int j = 0, jMax = line.length(); j < jMax; j++) 
        {
            cells[k * W + j] = line[j] == ALIVE ? ALIVE: DEAD;
        }
    }

    file.close();
}

void saveCellsToFile(string path, char *cells)
{
    ofstream fout(path);

    if (!fout.is_open()) 
    {
        cerr << "Файл не окрывается." << endl;
        return;
    }

    for (int i = 0, j = W * H; i < j; i++) 
    {
        fout << cells[i];
        if (i != 0 && (i + 1) % W == 0) 
        {
            fout << '\n';
        }
    }

    fout.close();
}

void printCells(char *cells, int current = -1, bool green = false) 
{
    system("clear");

    for (int i = 0, j = W * H; i < j; i++) 
    {

        if (i == current) 
        {
            if (green) 
            {
                cout << "\033[1;32m";
            } 
            else 
            {
                cout << "\033[1;31m";
            }
        }

        cout << (i == current ? '*' : cells[i]);
        
        if (i == current)
        {
            cout << "\033[0m";
        }
        
        if (i != 0 && (i + 1) % W == 0) 
        {
            cout << '\n';
        }
    }

    usleep(45 * 1000);
}

char nextState(char *cells, int index) 
{
    int aliveCells = 0;
    
    int x = index % W;
    int y = index / W;

    for (int j = y - 1, jMax = y + 2; j < jMax; j++) 
    {
        if (j < 0 || j > H) continue;
        for (int i = x - 1, iMax = x + 2; i < iMax; i++) 
        {
            if (i < 0 || i > W) continue;
            if (cells[j * W + i] == ALIVE) 
            {
                aliveCells += 1;
            }
        }
    }

    if (cells[index] == ALIVE) 
    {
        aliveCells -= 1; // except current
        return aliveCells < 2 || aliveCells > 3 ? DEAD : ALIVE;
    }

    return aliveCells == 3 ? ALIVE : DEAD;
}

int countAliveCells(char *cells)
{
    int aliveCells = 0;
    for (int i = 0, j = W * H; i < j; i++) 
    {
        if (cells[i] == ALIVE) 
        {
            ++aliveCells;
        }
    }

    return aliveCells;
}

class Statistic
{
    ofstream* fout;
    bool headersPrinted;

public:
    Statistic(string path)
    {
        fout = new ofstream(path);
        headersPrinted = false;
    }
    
    ~Statistic()
    {
        delete fout;
    }

    void write(int round, int alive) 
    {
        if (!headersPrinted)
        {
            headersPrinted = true;
            string line{ "Поколение;Живые клетки\n" };
            fout->write(line.c_str(), line.length());
        }

        string roundStr = to_string(round);
        string aliveStr = to_string(alive);
        
        fout->write(roundStr.c_str(), roundStr.length());
        fout->write(";", 1);
        fout->write(aliveStr.c_str(), aliveStr.length());
        fout->write("\n", 1);
        fout->flush();
    }
};

int main()
{
    char cells[W * H], nextCells[W * H];
    loadCellsFromFile("initial.txt", cells);
    
    Statistic stat("statistic.csv");

    int round{ 0 };
    int roundDiff{ 0 };

    stat.write(round, countAliveCells(cells));

    do 
    {
        ++round;
        roundDiff = 0;

        for (int i = 0, j = W * H; i < j; i++)
        {
            char nextCellState = nextState(cells, i);

            if (nextCellState != cells[i])
            {
                ++roundDiff;
            }
            
            nextCells[i] = nextCellState;
            printCells(cells, i, nextCellState == ALIVE);
        }

        stat.write(round, countAliveCells(nextCells));
        strcpy(cells, nextCells);
    } while (roundDiff > 0);

    saveCellsToFile("out.txt", cells);

    return 0;
}
