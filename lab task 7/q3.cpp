#include <iostream>
#include <iomanip>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() {
        return amount * exchangeRate;
    }

    virtual void displayCurrency() {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << ") "
             << fixed << setprecision(2) << amount << endl;
    }

    double convertTo(Currency &targetCurrency) {
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency.exchangeRate;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() override {
        cout << "Dollar: " << currencySymbol << fixed << setprecision(2) << amount << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

    void displayCurrency() override {
        cout << "Euro: " << currencySymbol << fixed << setprecision(2) << amount << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "?", 0.013) {}

    void displayCurrency() override {
        cout << "Rupee: " << currencySymbol << fixed << setprecision(2) << amount << endl;
    }
};

int main() {
    Dollar usd(100);
    Euro eur(50);
    Rupee inr(5000);

    cout << "\n--- Displaying Currencies ---\n";
    usd.displayCurrency();
    eur.displayCurrency();
    inr.displayCurrency();

    cout << "\n--- Converting 100 USD to EUR ---\n";
    double convertedToEuro = usd.convertTo(eur);
    cout << "100 USD is approximately " << fixed << setprecision(2) << convertedToEuro << " EUR\n";

    cout << "\n--- Converting 5000 INR to USD ---\n";
    double convertedToUsd = inr.convertTo(usd);
    cout << "5000 INR is approximately " << fixed << setprecision(2) << convertedToUsd << " USD\n";

    return 0;
}

