#include <iostream>
using namespace std;

class Car
{
public:
	virtual void show() = 0;
private:

};

class RunCar : public Car
{
public:
	virtual void show()
	{
		cout<<"我在地上开"<<endl;
	}
private:

};
class SwimCar : public Car
{
public:
	SwimCar(Car *car){
		swimCar = car;
	}
	virtual void show()
	{
		swimCar->show();
		cout<<"我在水里开"<<endl;
	}

private:
	Car *swimCar;
};

class FlyCar : public Car
{ 
public:
	FlyCar(Car *car){
		flyCar = car;
	}
	void show()
	{
		flyCar->show();
		cout<<"我在天上开"<<endl;
	}

private:
	Car *flyCar;
};

void main()
{
	Car *car;
	car = new RunCar();
	car->show();
	cout<<"--------------------------"<<endl;
	SwimCar *swimCar = new SwimCar(car);
	swimCar->show();
	cout<<"--------------------------"<<endl;
	FlyCar *flyCar = new FlyCar(swimCar);
	flyCar->show();

	system("pause");
	return;
}