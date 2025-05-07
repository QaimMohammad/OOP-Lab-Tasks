#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;

    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string shopName;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string name) : shopName(name) {
        menu.push_back(MenuItem("Espresso", "Drink", 2.5));
        menu.push_back(MenuItem("Cappuccino", "Drink", 3.0));
        menu.push_back(MenuItem("Latte", "Drink", 3.5));
        menu.push_back(MenuItem("Croissant", "Food", 1.5));
        menu.push_back(MenuItem("Sandwich", "Food", 2.0));
    }

    void addOrder(string item) {
        for (auto& menuItem : menu) {
            if (menuItem.name == item) {
                orders.push_back(item);
                return;
            }
        }
        cout << "This item is currently unavailable" << endl;
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
        double total = 0.0;
        for (const string& order : orders) {
            for (const auto& menuItem : menu) {
                if (menuItem.name == order) {
                    total += menuItem.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        string cheapest;
        double minPrice = DBL_MAX;
        for (const auto& menuItem : menu) {
            if (menuItem.price < minPrice) {
                minPrice = menuItem.price;
                cheapest = menuItem.name;
            }
        }
        return cheapest;
    }

    void drinksOnly() {
        for (const auto& menuItem : menu) {
            if (menuItem.type == "Drink") {
                cout << menuItem.name << endl;
            }
        }
    }

    void foodOnly() {
        for (const auto& menuItem : menu) {
            if (menuItem.type == "Food") {
                cout << menuItem.name << endl;
            }
        }
    }
};

int main() {
    CoffeeShop shop("Java Coffee");
    
    shop.addOrder("Espresso");
    shop.addOrder("Sandwich");

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

