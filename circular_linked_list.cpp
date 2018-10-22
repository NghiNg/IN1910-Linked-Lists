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

class CircLinkedList {
    private:
        Node* head;
        Node* tail;
        int size;

        Node* get_node(int index) {
            if(head == nullptr) {
                throw out_of_range("Size Error: List is empty!");
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

        CircLinkedList(int range) {
            head = nullptr;
            tail = nullptr;
            size = 0;
            for(int i=1; i<=range; i++) {
                append(i);
            }
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

        int length() {
           return size;
        }

        void print() {
            Node* current = head;
            cout << "[";
            int counter = 0;
            while(counter != size-1) {
                cout << current->value;
                cout << ", ";
                current = current->next;
                counter++;
            }
            cout << current->value << "]" << endl;
        }

        void remove(int index) {
            //Removes a node at a set index.
            Node* before;
            Node* current;
            current = get_node(index);
            if (size == 1) {
                cout << "head" << head->value << endl;
                head = nullptr;
                delete current;
                size -= 1;
                return;
            }
            if (index == size-1) {
                before = get_node(index-1);
                before->next = nullptr;
            } else if (index == 0) {
                head = get_node(1);
                cout << get_node(0)->value << endl;         //I think the issue might be that it's get_node(1) and not 0, but it bugs.
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

        vector<int> josephus_sequence(int k) {
            vector<int> jos_seq;
            cout << "test 1" << endl;
            while (size != 0) {
                cout << "test 2" << endl;
                int dead_man = pop(k);
                cout << dead_man << endl;
                jos_seq.push_back(dead_man);
                cout << "test 3" << endl;
            }
            if (size == 0) {
                return jos_seq;
            }
            return jos_seq;
        }
};

int main() {
    CircLinkedList test(2);
    test.pop(1);
    test.print();
    test.pop(2);
    cout << test.length() << endl;
    //cout << test.josephus_sequence(1)[1] << endl;
    cout << 5 << endl;
    return 0;
}
