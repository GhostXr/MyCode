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
	Fruit *createFruit(char *pName)
	{
		if (strcmp(pName, "banana") == 0)
		{
			return new Banana;
		}
		else if (strcmp(pName, "apple") == 0)
		{
			return new Apple;
		}
		else
		{
			return NULL;
		}
	}

private:

};

void main()
{
	FruitFactory *fruitFactory = new FruitFactory;

	Fruit *fruit;
	fruit = fruitFactory->createFruit("banana");
	fruit->getFruit();
	delete(fruit);
	
	fruitFactory->createFruit("apple");
	fruit->getFruit();
	delete(fruit);

	delete(fruitFactory);
	system("pause");
	return;
}