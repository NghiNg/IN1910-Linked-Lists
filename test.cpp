// expre_Using_delete.cpp  
struct UDType   
{  
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