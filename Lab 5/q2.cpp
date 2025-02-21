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
				cars[i]->display();
			}
		}
};

int main(){
	Car car1("Toyota",101);
	Car car2("Honda",102);
	Car car3("Alto",103);
	Garage garage;
	garage.parkCar(&car1);
	garage.parkCar(&car2);
	garage.parkCar(&car3);
	garage.listCars();
	
	return 0;
}
