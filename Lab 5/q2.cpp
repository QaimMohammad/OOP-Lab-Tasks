#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Car{
	private:
		string name;
		int id;
	public:
		Car(string Carname,int CarId): name(Carname),id(CarId) {}
		void display(){
		cout<< "Car Name:" <<name<< "Car ID:" <<id<<endl;
		cout<<endl;
	}
	
};
class Garage{
	private:
		vector<Car*>cars;
	public:
		void parkCar(Car* car){
			cars.push_back(car);
		}
		void listCars(){
			for(size_t i=0;i<cars.size();i++){
				if(car[i]){
				cars[i]->display();}
				else{
				cout<<"Attempting to Access unavailable data!"<<endl;
				}
			}
		}
};
void demonstratePitfall() {
    Garage garage;
    {
        Car tempCar("Temporary", 999);
        garage.parkCar(&tempCar);
        cout << "Inside scope:" << endl;
        garage.listCars();
    } 
    
    cout << "Outside scope:" << endl;
    garage.listCars(); 
}

int main(){
	Car car1("Toyota",101);
	Car car2("Honda",102);
	Car car3("Alto",103);
	Garage garage;
	garage.parkCar(&car1);
	garage.parkCar(&car2);
	garage.parkCar(&car3);
	garage.listCars();
	
	cout<<"Demonstrating Pitfall:"<<endl;
	demonstratePitfall();
	
	return 0;
}
