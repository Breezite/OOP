#include <iostream>
#include "item.h"
#include "Grocery.h"
#include "Electronic.h"
#include "Clothing.h"
#include "Book.h"
#include "Toy.h"
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int parseInt(const string& text){
    int value = stoi(text);
    return value;
}

double parseDouble(const string& text){
    double value = stod(text);
    return value;
}

vector<Item*> restore(ifstream& in){
    vector<Item*> restoredItems;
    string line;
    int lineNumber = 0;

    while(getline(in, line)){
        lineNumber++;

        istringstream record(line);
        vector<string> fields;
        string field;

        while (getline(record, field, '|')){
            fields.push_back(field);
        }

        int typeID = parseInt(fields[0]);
        string name = fields[1];
        int quantity = parseInt(fields[2]);
        double price = parseDouble(fields[3]);

        switch (typeID){
            case 0: {
                restoredItems.push_back(new Item(name, quantity, price));
                break;
            }
            case 1: {
                Date expiry = {parseInt(fields[4]), parseInt(fields[5]), parseInt(fields[6])};
                restoredItems.push_back(new Grocery(name, quantity, price, expiry));
                break;
            }
            case 2: {
                string origin = fields[4];
                double guarantee = parseDouble(fields[5]);
                restoredItems.push_back(new Electronic(name, quantity, price, origin, guarantee));
                break;
            }
            case 3 : {
                string material = fields[4];
                restoredItems.push_back(new Clothing(name, quantity, price, material));
                break;
            }
            case 4 : {
                int isbn = parseInt(fields[4]);
                string author = fields[5];
                restoredItems.push_back(new Book(name, quantity, price, isbn, author));
                break;
            }
            case 5 : {
                int size = parseInt(fields[4]);
                restoredItems.push_back(new Toy(name, quantity, price, size));
                break;
            }
        }
    }

    return restoredItems;
}

int main(){
    std::vector<Item*> items;



    int option;

    while (option != 9){
        cout << "1. Add Grocery" << endl;
        cout << "2. Add Electronic" << endl;
        cout << "3. Add Clothing" << endl;
        cout << "4. Add Book" << endl;
        cout << "5. Add Toy" << endl;
        cout << "6. View Cart" << endl;
        cout << "7. Save Cart" << endl;
        cout << "8. Load Cart" << endl;
        cout << "9. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        string name;
        int quantity;
        double price;

        if (option > 0 && option < 6){
            cout << "Enter name of item: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;
        }

        if (option == 1){
            Date expiry;
            cout << "Enter expiry day: ";
            cin >> expiry.day;
            cout << "Enter expiry month: ";
            cin >> expiry.month;
            cout << "Enter expiry year: ";
            cin >> expiry.year;
            
            items.push_back(new Grocery(name, quantity, price, expiry));
        }
        else if (option == 2){
            string origin;
            double guarantee;
            cout << "Enter origin: ";
            cin >> origin;
            cout << "Enter years of guarantee: ";
            cin >> guarantee;

            items.push_back(new Electronic(name, quantity, price, origin, guarantee));
        }
        else if (option == 3){
            string material;
            cout << "Enter material: ";
            cin >> material;

            items.push_back(new Clothing(name, quantity, price, material));
        }
        else if (option == 4){
            int isbn;
            string author;
            cout << "Enter isbn: ";
            cin >> isbn;
            cout << "Enter author: ";
            cin >> author;

            items.push_back(new Book(name, quantity, price, isbn, author));
        }
        else if (option == 5){
            bool size;
            cout << "Enter size (Small 0 / Big 1): ";
            cin >> size;

            items.push_back(new Toy(name, quantity, price, size));
        }
        else if (option == 6){
            cout << endl;
            cout << "This is your cart" << endl;
            for (int i = 0; i < items.size(); i++){
                (*items[i]).display();
            }
        }
        else if (option == 7){
            ofstream out ("cart.txt");
            
            for (Item* item : items){
                (*item).persist(out);
            }
            out.close();
            
            if (out) {
                cout << "Cart was successfully saved" << endl;
            } else {
                cout << "Cart was unsuccessfully saved" << endl;
            }
        }
        else if (option == 8){
            ifstream in ("cart.txt");
            
            vector<Item*> loaded = restore(in);

            items.swap(loaded);
            for(Item* item : loaded){
                delete item;
            }
            
            cout << "Cart restored" << endl;
        }
        else if (option == 9){
            cout << "Thank you for shopping with us!" << endl;
        }

    }

    for (Item* item : items){
        delete item;
    }
    items.clear();

    return 0;
}