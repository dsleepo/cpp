#include <iostream>
using namespace std;

const int maxQueueSize = 100;

class Queue {
    char q[maxQueueSize];
    int size;
    int putloc, getloc;

    public:
        Queue(int len) {
            if (len > maxQueueSize) {
                len = maxQueueSize;
            } else if (len <= 0) {
                len = 1;
            }
            size = len;
            putloc = getloc = 0;
        }

        void put(char ch) {
            if (putloc == size) {
                cout << " --  Очередь заполнена.";
                return;
            }
            putloc++;
            q[putloc] = ch;
        }

        char get() {
            if (putloc == getloc) {
                cout << " -- Очередь пуста" << endl;
                return 0;
            }
            getloc++;
            return q[getloc];
        }
};

int main()
{
    Queue q(26);

    q.get(); // print empty 
    
    for (int i = 0; i < 26; i++) {
        q.put('A' + i);
    }

    while (char ch = q.get()) {
        cout << ch << endl;
    }


    return 0;
}