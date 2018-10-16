#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class ArrayList {
private:
    int *data;
    int capacity;

    void resize() {
        capacity *= 2;
        int *tmp = new int[capacity];
        for (int i=0; i<size; i++) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
    }

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

    int length() {
        return size;
    }

    void append(int n) {
        if (size < capacity) {
            data[size] = n;
            size += 1;
        } else {
            resize();
            data[size] = n;
            size += 1;
        }
    }

    int& get(int i) {
        if ((0 <= i) && (i < size)) {
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

    void insert(int val, int index) {
        if (index>size) {
            throw range_error("Index too large! Must insert within length.");
        }
        int *tmp = new int[capacity];
        for (int i=0; i<index; i++) {
            tmp[i] = data[i];
        }
        tmp[index] = val;
        size += 1;
        for (int i=index+1; i<size; i++) {
            tmp[i] = data[i-1];
        }
        delete[] data;
        data = tmp;
    }
    
    void remove(int index){
        if (index>size) {
            throw range_error("Index too large! Must insert within length.");
        }
        int *tmp = new int[capacity];
        for (int i=0; i<index; i++) {
            tmp[i] = data[i];
        }
        size -= 1;
        for (int i=index; i<size+1; i++) {
            tmp[i] = data[i+1];
        }
        delete[] data;
        data = tmp;
    }

    int pop(int index){
        int popped=data[index];
        remove(index);
        return popped;
    }

    int pop(){
        int a = data[length()];
        pop(length());
        return a;
    }
};

bool is_prime(int n) {
    for(int i=2; i<n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ArrayList primes;
    int s = 1;
    while(primes.length()<10) {
        if(is_prime(s)){
            primes.append(s);
        }
        s++;
    }
    primes.print();
    cout << primes.pop() << endl;
    primes.print();
    return 0;
}
