#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string partNum, string partDesc, int qty, double price)
        : partNumber(partNum), partDescription(partDesc), quantity(qty), pricePerItem(price) {
        if (quantity <= 0) quantity = 0;
        if (pricePerItem <= 0.0) pricePerItem = 0.0;
    }

    double getInvoiceAmount() {
        return quantity * pricePerItem;
    }

    void displayInvoice() {
        cout << "Part Number: " << partNumber << endl;
        cout << "Part Description: " << partDescription << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per Item: " << pricePerItem << endl;
        cout << "Invoice Amount: " << getInvoiceAmount() << endl;
    }
};

int main() {
    Invoice invoice("1234", "Hammer", 5, 10.0);
    invoice.displayInvoice();

    return 0;
}

