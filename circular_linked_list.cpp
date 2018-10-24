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

        CircLinkedList(vector<int> initial) {
            head = nullptr;
            tail = nullptr;
            size = 0;
            for (int e: initial) {
                append(e);
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

        void move_head(int index) {
            tail = get_node(index-1);
            head = get_node(index);
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
                cout << "checkpoint size == 1" << endl;
                head = nullptr;
                delete current;
                size -= 1;
                return;
            }
            if (index == size-1) {
                cout << "checkpoint index == size-1" << endl;

                before = get_node(index-1);
                before->next = head;
                tail = before;
            } else if (index%size == 0) {
                cout << "checkpoint index-mod-size == 0" << endl;
                before = get_node(index-1);
                before->next = get_node(index+1);
                head = before->next;
            } else {
                cout << "checkpoint else" << endl;
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

        vector<int> josephus_sequence(int k) {
            // Vi vil fjerne hvert k-te element. dvs dersom k=1, hopper vi over
            // ett element og fjerner det neste.

            vector<int> jos_seq; // Vi lager først en vektor vi skal putte de døde inn i

            while (size != 0) {
                //cout << "while size: " << size << endl;
                int dead_man = pop(k);
                move_head(k);
                cout << "new head value: " << head->value << endl;
                jos_seq.push_back(dead_man);
            }
            return jos_seq;
        }
};


int last_man_standing(int n, int k) {
    // Vi antar her at alle tidligere funksjoner fungerer feilfritt.
    // Vi kommer tilbake og retter dem senere.
    CircLinkedList army(n);
    vector<int> seq = army.josephus_sequence(k);
    CircLinkedList dead(seq);
    dead.print();
    return dead.pop();
}


int main() {
    //CircLinkedList test({0,1,3,4});
    //cout << test.pop(4) << endl;
    cout << last_man_standing(4, 4) << endl;

    cout << "test end" << endl;
    return 0;
}
