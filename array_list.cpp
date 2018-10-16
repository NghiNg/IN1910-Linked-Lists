#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class ArrayList {
private:
    int *data;
    int capacity;

public:
    int size;

    ArrayList() {
        size = 0;
        capacity = 1;
        data = new int[capacity];
    }

    ArrayList(vector<int> initial) {
        size = 0;
        capacity = 1;
        data = new int[capacity];

        for (int e: initial) {
            append(e);
        }
    }

    ~ArrayList() {
        delete[] data;
    }

    void append(int n) {
        if (size < capacity) {
            data[size] = n;
            size += 1;
        } else {
            resize();
        }
    }

    int& get(int i) {
        if (0 <= i and i < size) {
            return data[i];
        }
    }

    int& operator[] (int i) {
        return get(i);
    }

    void print() {
        cout << "[";
        for (int i=0; i<size-1; i++) {
            cout << data[i];
            cout << ", ";
        }
        cout << data[size-1] << "]" << endl;
    }

    void resize() {
        capacity *= 2;
        int *tmp = new int[capacity];
        for (int i=0; i<size; i++) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
    }
};

int main() {
    ArrayList example({1,2,3,4,5});
    example.append(23);
    example.append(22);
    example.append(24);
    for (int i=0; i<example.size; i++) {
        cout << example.get(i) << endl;
    }
    example.print();
    cout << example[5] << endl;
    return 0;
}
