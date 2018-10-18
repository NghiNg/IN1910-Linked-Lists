#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int n) {
        value = n;
        next = nullptr;
    }

    Node(int n, Node* p) {
        value = n;
        next = p;
    }
};
class LinkedList {
    private:
        Node* head;
        Node* tail;
        int size;

        Node* get_node(int index) {
            if (index<0 or index>size) {
                throw range_error("IndexError: Index out of range.");
            }
            Node* current = head;
            for (int i=0; i<index; i++) {
                current = current->next;
            }
            return current;
        }

    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

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
                tail = head;
                return;
            }
            Node* current;
            current = tail;
            current->next = new Node(val);
            tail = current->next;
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

        int &operator[](int index) {
            return get_node(index)->value;
        }

        void insert(int val, int index) {
            Node* tmp;
            Node* current;

            tmp = get_node(index);
            current = get_node(index-1);

            current->next = new Node(val);
            current = current->next;
            current->next = tmp;
            size += 1;
        }

        void remove(int index) {
            Node* before;
            Node* after;
            Node* current;
            before = get_node(index-1);
            after = get_node(index+1);
            before->next = after;
            current = get_node(index);
            delete current;
            size -= 1;
        }

        int pop(int index) {
            Node* tmp;
            tmp = get_node(index);
            remove(index);
            size -= 1;
            return tmp->value;
        }

        int pop() {
            return pop(size);
        }
};



int main() {
    LinkedList test;
    test.append(5);
    test.print();
    test.append(82);
    test.append(83);
    test.append(6);
    test.append(9);
    test.insert(84, 2);
    test.print();
    test.pop(5);
    cout << test[2] << endl;
    return 0;
}
