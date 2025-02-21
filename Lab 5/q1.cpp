#include<iostream>
using namespace std;

class Engine{
	private:
		bool isRunning;
	public:
	  Engine(){ cout<<"Engine Created!"<<endl;}
	  ~Engine(){ cout<<"Engine Destroyed!"<<endl;}
	  
	  void start(){
	  	if(!isRunning){
		  
	  	 isRunning=true;
	  	 cout<<"Engine Started!"<<endl;}
	  	else{
	  		cout<<"Engine Already Running!"<<endl;
		  }
	  }
	  void end(){
	  	if(isRunning=true){
	  		isRunning=false;
	  		cout<<"Engine Stopped!"<<endl;
		  }
		else{
			cout<<"Engine Already Stopped!"<<endl;
		}
	  }	  
};
class Car{
	private:
		Engine engine;
	public:
		Car(){cout<<"Car Created!"<<endl;}
		~Car(){cout<<"Car Destroyed!"<<endl;}
		startCar(){
			engine.start();
		}
		stopCar(){
			engine.end();
		}
};

int main(){
 Car myCar;
 myCar.startCar();
 myCar.stopCar();
 
 return 0;
}
