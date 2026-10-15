#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>

using namespace std;

class University{
    private:
        string universityName;

    public:
        University(const string& name);
        string getUniveristyName() const;
};

#endif