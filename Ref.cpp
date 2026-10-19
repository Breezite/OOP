#include <iostream>
using namespace std;

struct RefClass {
    int data;
    RefClass(int d) : data(d) {}
};

struct MyRefClass {
    int value;
    int anotherValue; // New int field
    RefClass* pointer;
    // Initialization
    void init(int v, int anotherV) {
    value = v;
    anotherValue = anotherV;
    pointer = new RefClass(10); // Allocating on the heap
}
// Deinitialization
void deinit() {
    delete pointer; // Deallocate the heap memory
}
// Member function to modify value
void setValue(int newValue) {
    value = newValue;
}
// Member function to multiply values
int multiplyValues() {
    return value * anotherValue;
}
// Yet another Member function
void printValueAndPointer() {
    cout << "Value: " << value << endl;
    cout << "Another Value: " << anotherValue << endl;
    cout << "Pointer Data: " << pointer->data << endl;
    int result = multiplyValues();
    cout << "Result of multiplication: " << result << endl;
}
};

int main() {
    // Create instance and initialize
    MyRefClass obj;
    obj.init(5, 7);
    //Use
    obj.printValueAndPointer();
    int resultFromMain = obj.multiplyValues();
    cout << "Result of multiplication from main: " << resultFromMain << endl;
    obj.value = 9;
    obj.setValue(10);
    obj.printValueAndPointer();
    // Deinitialize and free resources
    obj.deinit();
    return 0;
}