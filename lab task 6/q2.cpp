#include <iostream>
#include <string>
using namespace std;

class Vehicles {
protected:
    float price;
public:
    void setPrice(float p) {
        price = p;
    }

    void displayPrice() {
        cout << "Price: $" << price << endl;
    }
};

class Car : public Vehicles {
protected:
    int seatingCapacity;
    int numberOfDoors;
    string fuelType;
public:
    void setCarDetails(int sc, int nd, const string& ft) {
        seatingCapacity = sc;
        numberOfDoors = nd;
        fuelType = ft;
    }

    void displayCarDetails() {
        displayPrice();
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Doors: " << numberOfDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Motorcycle : public Vehicles {
protected:
    int numberOfCylinders;
    int numberOfGears;
    int numberOfWheels;
public:
    void setMotorcycleDetails(int nc, int ng, int nw) {
        numberOfCylinders = nc;
        numberOfGears = ng;
        numberOfWheels = nw;
    }

    void displayMotorcycleDetails() {
        displayPrice();
        cout << "Number of Cylinders: " << numberOfCylinders << endl;
        cout << "Number of Gears: " << numberOfGears << endl;
        cout << "Number of Wheels: " << numberOfWheels << endl;
    }
};

class Audi : public Car {
private:
    string modelType;
public:
    void setAudiDetails(const string& mt) {
        modelType = mt;
    }

    void displayAudiDetails() {
        displayCarDetails();
        cout << "Model Type: " << modelType << endl;
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;
public:
    void setYamahaDetails(const string& mt) {
        makeType = mt;
    }

    void displayYamahaDetails() {
        displayMotorcycleDetails();
        cout << "Make Type: " << makeType << endl;
    }
};

int main() {
    Audi audi;
    Yamaha yamaha;

    audi.setPrice(40000);
    audi.setCarDetails(5, 4, "Petrol");
    audi.setAudiDetails("Q7");

    yamaha.setPrice(15000);
    yamaha.setMotorcycleDetails(4, 6, 2);
    yamaha.setYamahaDetails("YZF-R1");

    cout << "\nAudi Car Details:\n";
    audi.displayAudiDetails();

    cout << "\nYamaha Motorcycle Details:\n";
    yamaha.displayYamahaDetails();

    return 0;
}

