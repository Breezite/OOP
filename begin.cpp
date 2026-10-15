#include <iostream>
#include <string>
#include <cstdio>

class Student{
public:
    Student(const std::string& name)
        : name(name) {}

    void display() const{
        printf("Name: %s", name.c_str());
    }

private:
    std::string name;

};

int main() {
    Student s1("a");
    puts("S1 details");
    s1.display();

    return 0;
}