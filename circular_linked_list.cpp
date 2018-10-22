#include <iostream>
#include <vector>
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

class CircLinkedList {
    private:
        Node* head;
        Node* tail;
        int size;

        Node* get_node(int index) {
            if(head == nullptr) {
                throw range_error("Size Error: List is empty!");
            }
            Node* current = head;
            for (int i=0; i<index; i++) {
                current = current->next;
            }
            return current;
        }

    public:
        CircLinkedList() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }


        ~CircLinkedList() {
            Node* current;
            Node* next;

            current = head;
            int counter = 0;
            while(counter != size) {
                next = current->next;
                delete current;
                current = next;
                counter++;
            }
        }

        void append(int val) {
            //Adds int to end of list.
            if(head==nullptr) {
                head = new Node(val);
                tail = head;
                size += 1;
                return;
            }
            Node* current;
            current = tail;
            current->next = new Node(val);
            tail = current->next;
            tail->next = head;
            size += 1;
        }

        int &operator[](int index) {
            return get_node(index)->value;
        }

    void print() {
        Node* current = head;
        cout << "[";
        int counter = 0;
        while(counter != size) {
            cout << current->value;
            cout << ", ";
            current = current->next;
            counter++;
        }
        cout << current->value << "]" << endl;
    }
};

int main() {
    CircLinkedList test();
    test.append(1);
    test.append(2);
    test.append(3);
    test.append(4);
    test.append(5);

    test.print();


    return 0;
}
