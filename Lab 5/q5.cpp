#include <iostream>
using namespace std;

class Car {
public:
    int engineHorsepower;
    int seatingCapacity;
    int noOfSpeakers;

    void setAttributes(int engineHP, int seatingCap, int speakers) const {
        const_cast<Car*>(this)->engineHorsepower = engineHP;
        const_cast<Car*>(this)->seatingCapacity = seatingCap;
        const_cast<Car*>(this)->noOfSpeakers = speakers;
    }

    void displayAttributes() {
        cout << "Engine Horsepower: " << engineHorsepower << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Speakers: " << noOfSpeakers << endl;
    }
};

int main() {
    Car car;
    car.setAttributes(250, 5, 8);
    car.displayAttributes();
    return 0;
}


