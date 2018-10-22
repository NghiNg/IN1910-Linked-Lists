#include <iostream>
#include <stdexcept>
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
class LinkedList {
    private:
        Node* head;
        Node* tail;
        int size;

        Node* get_node(int index) {
            if ((index<0) || (index>=size)) {
                throw out_of_range("IndexError: Index out of range.");
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

        LinkedList(vector<int> initial) {
            head = nullptr;
            tail = nullptr;
            size = 0;
            for (int e: initial) {
                append(e);
            }
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
            //Adds a node at set index.
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
            //Removes a node at a set index.
            Node* before;
            Node* current;
            current = get_node(index);
            if (size == 1) {
                head = nullptr;
                return;
            }
            if (index == size-1) {
                before = get_node(index-1);
                before->next = nullptr;
            } else if (index == 0) {
                head = get_node(1);
            } else {
                before = get_node(index-1);
                before->next = get_node(index+1);
            }
            delete current;
            size -= 1;
        }

        int pop(int index) {
            //Removes a node at an index and returns that nodes value.
            Node* tmp;
            tmp = get_node(index);
            int removed = tmp->value;
            remove(index);
            return removed;
        }

        int pop() {
            //Same as pop but only last node.
            return pop(size-1);
        }
};

int main() {
    LinkedList test({1,2,3,4,5});
    cout << "This is the initial list." << endl;
    test.print();
    cout << "Testing append, 4 integers." << endl;
    test.append(6);
    test.append(7);
    test.append(8);
    test.append(10);
    test.print();
    test.insert(9,8);
    cout << "Inserted 9 in index 8:" << endl;
    test.print();
    test.remove(4);
    cout << "Removed index 4." << endl;
    test.print();
    cout << "Pop first index: " << test.pop(0) << endl;
    test.print();
    cout << "Pop 3 index: " << test.pop(3) << endl;
    test.print();
    cout << "Pop last index: " << test.pop() << endl;
    test.print();
    return 0;
}
