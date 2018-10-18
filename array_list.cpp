#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class ArrayList {
private:
    int *data;

    void resize() {
        capacity *= 2;
        int *tmp = new int[capacity];
        for (int i=0; i<size; i++) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
    }

    void halve() {
        capacity /= 2;
        int *tmp = new int[capacity];
        for (int i=0; i<size; i++) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
    }


public:
    int size;
    int capacity;

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
            throw range_error("IndexError: Index too large! Must insert within length.");
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
        if(4*size<capacity) {
            shrink_to_fit();
        }
    }

    int pop(int index){
        int popped=data[index];
        remove(index);
        return popped;
    }

    int pop(){
        int a = data[size-1];
        pop(size);
        return a;
    }

    void shrink_to_fit() {
        while(size*2<capacity) {
            halve();
        }
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
    while(primes.length()<1000) {
        if(is_prime(s)){
            primes.append(s);
        }
        s++;
    }
    cout << "Capacity = " << primes.capacity << endl;        //Testing the capacity.
    
    for(int i=11; i<1000; i++) {
        primes.pop();
    }
    cout << "Capacity = " << primes.capacity << endl;        //Testing if capacity works after changing the list.

    primes.print();
    
    cout << "Length = " << primes.length() << endl;
    cout << "Pop = " << primes.pop() << endl;           //Testing if pop() works.
    
    primes.print();
    cout << "Length = " << primes.length() << endl;
    return 0;
}
