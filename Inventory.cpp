#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

/****************************************
*           Inventory System            *
*             Tucker Giovo              *
****************************************/

//Item object, stores a name, price, and quantity of items
class Item {
public:
    string name;
    double price;
    int quantity;
};

//Inventory class, manages a vector of Item objects
class Inventory {
private:
    vector<Item> items;

public:

    //Adds an item to the vector
    void addItem() {
        string inName;
        double inPrice;
        int inQuan;

        //Begins by asking name of the item
        cout << "What is the name of the item?\n> ";
        cin >> inName;

        //Checks if the item is in the vector already
        for (auto& item : items) {
            //If it finds the item, it will just add to the quantity
            if (item.name == inName) {
                cout << "Item found in inventory. How many to add?\n> ";
                cin >> inQuan;
                item.quantity += inQuan;
                return;
            }
        }

        //If it does not find the item, it creates a new one and asks for the other information
        Item newItem;

        newItem.name = inName;

        //Asks for price
        cout << "What is the price?\n> ";
        cin >> inPrice;
        newItem.price = inPrice;

        //Asks for quantity
        cout << "How many to add?\n> ";
        cin >> inQuan;
        newItem.quantity = inQuan;

        //Adds new item to the items vector
        items.push_back(newItem);
    }

    //Removes items from vector
    void removeItem() {
        string inName;
        int inNum;

        //Checks if there is anything in the vector, returns if there's nothing to remove
        if (items.empty()) {
            cout << "\nNo items\n";
            return;
        }

        //Asks the name of the item
        cout << "What is the name of the item?\n> ";
        cin >> inName;

        //Checks if the item is in the vector
        for (auto it = items.begin(); it != items.end(); ++it) {
            //If it finds the item, asks for how many to remove
            if (it->name == inName) {
                cout << "Item Found. How many to remove?\n> ";
                cin >> inNum;

                //Checks if number to remove is equal to or greater than total quantity available, removes the item from the vector if so
                if (inNum >= it->quantity) {
                    items.erase(it);
                    return;
                }

                //If it is not enough to delete the item, it just reduces quantity
                it->quantity -= inNum;
                return;
            }
        }

        //Hasn't found the designated item, returns at end of function
        cout << "\nItem not found.\n";
    }

    //Displays a list of items in the vector
    void displayItems() {
        //If no items, returns
        if (items.empty()) {
            cout << "\nNo items.\n";
            return;
        }

        //Makes sure the price will be in X.XX form
        cout << endl << fixed << setprecision(2);

        //Loops through the items and displays them each line
        for (size_t i = 0; i < items.size(); i++) {
            cout << i + 1 << ". " << items[i].name << " $" << items[i].price << ", Quantity: " << items[i].quantity << endl;
        }
    }
};

int main() {
    Inventory inventory;
    int command;
    bool cont = true;

    cout << "Welcome to the Inventory Management System!\n";

    //Main program loop
    while (cont) {
        cout << "\nCommands:\n1. Add Item\n2. Remove Item\n3. Display Inventory\n4. Exit\n> ";
        cin >> command;

        //Switch for options handling, just calls each function or ends the loop depending on input
        switch (command) {
            case 1:
                inventory.addItem();
                break;
            case 2:
                inventory.removeItem();
                break;
            case 3:
                inventory.displayItems();
                break;
            case 4:
                cont = false;
                break;
        }
    }
}