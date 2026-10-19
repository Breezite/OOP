#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>
using namespace std;

class Binops {
    private:
        double operand1;
        double operand2;
        char op;

    public:
        double getO1(){
            return operand1;
        }
        double getO2(){
            return operand2;
        }
        char getO(){
            return op;
        }
        void setO1(double newOperand1){
            operand1 = newOperand1;
        }
        void setO2(double newOperand2){
            operand2 = newOperand2;
        }
        void setO(char newOp){
            op = newOp;
        }
        
        double evaluate(){
            if (op == '+'){
                return operand1 + operand2;
            } else if (op == '-'){
                return operand1 - operand2;
            } else if (op == '*'){
                return operand1 * operand2;
            } else if (op == '/'){
                return operand1 / operand2;
            } else {
                cout << "Invalid operation" << endl;
            }
            return 0.0;
        }
};

bool checkOperand(double& value){
    bool flag = true;

    if (!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << "Invalid" << endl;
        flag = false;
    }

    string remaining;
    getline(cin, remaining);

    if (remaining.find_first_not_of(" \t\r") != string::npos) {
        cout << "Invalid due to complementary string input" << endl;
        flag = false;
    }

    return flag;
};

bool checkOperator(char& input){
    bool flag = true;
    string check;

    getline(cin, check);
    if (check.length() != 1){
        cout << "Invalid" << endl;
        flag = false;
    }
    else{
        istringstream iss(check);
        iss >> input;
        
        if (input != '+' && input != '-' && input != '*' && input != '/'){
            cout << "Invalid" << endl;
            flag = false;
        }
    }
    
    return flag;
}

int main() {
    Binops binops[4];

    fstream arbitraryFile;
    arbitraryFile.open("PracticalTask02.txt", ios::out);

    for(int i = 0; i < 4; i++){
        double x;
        char a;
        cout << "Enter first operand: ";
        cin >> x;
        while (!checkOperand(x)){
            cout << "Enter first operand: ";
            cin >> x;
        };

        binops[i].setO1(x);

        cout << "Enter second operand: ";
        cin >> x;
        while (!checkOperand(x)){
            cout << "Enter first operand: ";
            cin >> x;
        };
        binops[i].setO2(x);

        cout << "What operation do you wish to perform +, -, *, /: ";
        while (!checkOperator(a)){
            cout << "What operation do you wish to perform +, -, *, /: ";
        }
        binops[i].setO(a);

        arbitraryFile << binops[i].getO1() << " " << binops[i].getO() << " " << binops[i].getO2() << " = ";
        arbitraryFile << binops[i].evaluate() << endl;
    }
    arbitraryFile.close();
    //delete __;
    //__ = nullptr;

    return 0;
};