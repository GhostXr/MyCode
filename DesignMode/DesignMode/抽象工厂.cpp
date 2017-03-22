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
	virtual Fruit *createBanana() = 0;
	virtual Fruit *createApple() = 0;

private:

};

class SourthFactory : public FruitFactory
{
public:
	virtual Fruit *createBanana()
	{
		return new Banana;
	}
	virtual Fruit *createApple()
	{
		return new Apple;
	}
private:

};

class NorthFactory : public FruitFactory
{
public:
	virtual Fruit *createBanana()
	{
		return new Banana;
	}
	virtual Fruit *createApple()
	{
		return new Apple;
	}
private:

};

void main()
{
	FruitFactory *fruitFactory;;
	Fruit *fruit;

	fruitFactory = new SourthFactory;
	fruit = fruitFactory->createApple();
	fruit->getFruit();
	delete(fruit);
	fruit = fruitFactory->createBanana();
	fruit->getFruit();
	delete(fruit);
	
	fruitFactory = new NorthFactory;
	fruit = fruitFactory->createApple();
	fruit->getFruit();
	delete(fruit);
	fruit = fruitFactory->createBanana();
	fruit->getFruit();
	delete(fruit);

	delete(fruitFactory);
	system("pause");
	return;
}