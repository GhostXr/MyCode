#include <iostream>
using namespace std;

class Fruit
{
public:
	virtual void  getFruit() = 0;
private:

};

class Banana : public Fruit
{
public:
	virtual void  getFruit()
	{
		cout<< "我是香蕉。。。"<<endl;
	}
private:

};

class Apple : public Fruit
{
public:
	virtual void  getFruit()
	{
		cout<< "我是苹果。。。"<<endl;
	}
private:

};

class FruitFactory
{
public:
	virtual Fruit *createFruit() = 0;

private:

};

class BananaFactory : public FruitFactory
{
public:
	
	virtual Fruit *createFruit()
	{
		return new Banana;
	}
private:

};

class AppleFactory : public FruitFactory
{
public:
	
	virtual Fruit *createFruit()
	{
		return new Apple;
	}
private:

};

void main()
{
	FruitFactory *fruitFactory;;
	Fruit *fruit;

	fruitFactory = new BananaFactory;
	fruit = fruitFactory->createFruit();
	fruit->getFruit();
	delete(fruit);
	
	fruitFactory = new AppleFactory;
	fruit = fruitFactory->createFruit();
	fruit->getFruit();
	delete(fruit);

	delete(fruitFactory);
	system("pause");
	return;
}