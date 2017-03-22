#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "vector"
#include "string"
using namespace std;


class Person
{
public:
	Person(int age, char* name)
	{
		this->name = new char[strlen(name)+1];
 		strcpy(this->name, name);
		this->age = age;
	}
	~Person()
	{
		if (name != NULL)
		{
			delete[] name;
			name = NULL;
			age = 0;
		}
	}

	/*Person(const Person& per)
	{
		this->name = new char[strlen(per.name)+1];
		strcpy(this->name,per.name);
		this->age = per.age;
	}

	Person operator=(const Person& per)
	{
		if (name != NULL)
		{
			delete[] name;
			name = NULL;
			age = 0;
		}

		this->name = new char[strlen(per.name)+1];
		strcpy(this->name,per.name);
		this->age = per.age;
	}*/

	void printT()
	{
		cout<<name<<" "<<this->age<<endl;	
	}
private:
	char* name;
	int age;
};

void test1()
{
	vector<Person> st;
	Person p1(21, "уер╩");

	st.push_back(p1);

	for(vector<Person>::iterator it = st.begin(); it != st.end(); it++)
	{
		it->printT();
	}
	
	cout<<endl;

}

void main()
{
	test1();
	//test2();

	system("pause");
	return;
}