#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CoffeeShop {
public:
    string shopName;
    vector<string> menu;
    vector<string> orders;

    void setMenu() {
        menu = {"Espresso", "Cappuccino", "Latte", "Croissant", "Sandwich"};
    }

    void addOrder(string item) {
        if (find(menu.begin(), menu.end(), item) != menu.end()) {
            orders.push_back(item);
        } else {
            cout << "This item is currently unavailable!" << endl;
        }
    }

    void fulfillOrder() {
        if (!orders.empty()) {
            cout << "The " << orders.front() << " is ready!" << endl;
            orders.erase(orders.begin());
        } else {
            cout << "All orders have been fulfilled!" << endl;
        }
    }

    void listOrders() {
        if (!orders.empty()) {
            for (const string& order : orders) {
                cout << order << endl;
            }
        } else {
            cout << "No orders taken." << endl;
        }
    }

    double dueAmount() {
        double amount = 0.0;
        for (const string& order : orders) {
            if (order == "Espresso") amount += 2.5;
            else if (order == "Cappuccino") amount += 3.0;
            else if (order == "Latte") amount += 3.5;
            else if (order == "Croissant") amount += 1.5;
            else if (order == "Sandwich") amount += 2.0;
        }
        return amount;
    }

    string cheapestItem() {
        return "Espresso";
    }

    void drinksOnly() {
        for (const string& item : menu) {
            if (item != "Croissant" && item != "Sandwich") {
                cout << item << endl;
            }
        }
    }

    void foodOnly() {
        for (const string& item : menu) {
            if (item == "Croissant" || item == "Sandwich") {
                cout << item << endl;
            }
        }
    }
};

int main() {
    CoffeeShop shop;
    shop.setMenu();
    shop.addOrder("Espresso");
    shop.addOrder("Sandwich");
    shop.addOrder("Cappuccino");

    cout << "\nOrders list:\n";
    shop.listOrders();

    cout << "\nDue Amount: $" << shop.dueAmount() << endl;

    cout << "\nCheapest Item: " << shop.cheapestItem() << endl;

    cout << "\nDrinks Only:\n";
    shop.drinksOnly();

    cout << "\nFood Only:\n";
    shop.foodOnly();

    shop.fulfillOrder();
    shop.fulfillOrder();
    shop.fulfillOrder();

    return 0;
}

