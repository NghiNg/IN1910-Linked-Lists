#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node(int n) {
    value = n;
    next = nullptr;
}

Node(int n, Node* p) {
    value = n;
    next = p;
}

class LinkedList {
    private:
        Node* head;
        int size;
    public:
        LinkedList() {
            head = nullptr;
            size = 0
        };

        ~LinkedList() {
            Node* current;
            Node* next;

            current = head;
            while(current != nullptr) {
                next = current->next;
                delete current;
                current = next;
            }
        }

        void append(int val) {
            if(head==nullptr) {
                head = new Node(val);
                return;
            }
            Node* current;
            current = head;
            while(current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(val);
            size += 1;
        }

        void print() {
            Node* current = head;
            cout << "[";
            while(current->next != nullptr) {
                cout << current->value;
                cout << ", ";
                current = current->next;
            }
            cout << current->value << "]" << endl;
        }

        int length() {
            return size;
        }
}



int main() {


    return 0
}
