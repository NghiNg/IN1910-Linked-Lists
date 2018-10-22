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

        vector<int> josephus_sequence(int k) {
            vector<int> jos_seq;
            while(size != 0) {
                int dead_man = pop(k);

                jos_seq.push_back(dead_man);
                cout << jos_seq[0] << endl;

            }
            cout << jos_seq[2] << endl;

            return jos_seq;
        }
};

int main() {
    CircLinkedList test(4);

    cout << test.josephus_sequence(1)[1] << endl;
    cout << 1 << endl;

    return 0;
}
