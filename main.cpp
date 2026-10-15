#include <iostream>

using namespace std;

class MyClass{
    private:
        int field1;
        string field2;
    
    public:

    //deffault constructor
    MyClass() : field1(1), field2("word") {
        cout << "Success" << endl;
    }

    //Deconstructor
    ~MyClass() {
        cout << "Deconstructor called" << endl;
    }

    //Parameterised constructor
    MyClass(int  f1, string f2) : field1(f1), field2(f2){
        cout << "Parameterised Constructor" << endl;
    }

    int getField1() const {
        return field1;
    }
    string getField2() const {
        return field2;
    }
    void setField1(int f1){
        field1 = f1;
    }
    void setField2(const string& f2){
        field2 = f2;
    }
};
int main(int, char**){
    std::cout << "Hello, from Course!\n" << endl;

    MyClass obj1;
    cout << "Field1: " << obj1.getField1() << endl;
    cout << "Field2: " << obj1.getField2() << endl;

    //Object on a heap
    MyClass* obj2 = new MyClass(20, "swan");

    delete obj2;
    obj2 = nullptr;

    MyClass objArray[3];
    for (int i = 0; i < 3; i++){
        objArray[i].setField1(i);
        objArray[i].setField2("Done");
    }
    for (int i = 0; i < 3; i++){
        cout << objArray[i].getField1() << endl;
        cout << objArray[i].getField2() << endl;
    }


    return 0;
}