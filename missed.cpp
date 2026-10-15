#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "University.h"

using namespace std;

class Person {
    protceted:
        string name;
        int age;
        University* university;
    
    public:
        Person(const string& n, int a);
        virtual ~Person();
        virttual void displayInfo() const;

        string etName() const;
        int getAfe() const;
        University* getUniversity() const;

        void setName(const string& n);
        void setAge(int a)
        void setUniversity(University* uni);
};

#endif