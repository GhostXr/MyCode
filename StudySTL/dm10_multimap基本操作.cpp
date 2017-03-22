#include <iostream>
#include "map"
#include "string"
using namespace std;

class Person
{
public:
	int age;
	string name;
	string dep;
	double phone;

};

void test1()
{
	multimap<string, Person> st;
	Person p1, p2, p3, p4, p5;
	p1.name = "张一";
	p1.age = 21;
	
	p2.name = "张二";
	p2.age = 22;
	
	p3.name = "张三";
	p3.age = 23;
	
	p4.name = "张四";
	p4.age = 24;
	
	p5.name = "张五";
	p5.age = 25;

	st.insert(pair<string, Person>("sale", p1));
	st.insert(pair<string, Person>("sale", p2));
	st.insert(pair<string, Person>("develop", p3));
	st.insert(pair<string, Person>("develop", p4));
	st.insert(pair<string, Person>("math", p5));

	for(multimap<string, Person>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout<<it->first <<" "<<it->second.name<<" "<<it->second.age<<endl;
	}
	cout<<endl;

	int num = st.count("develop");
	cout<<"develop num == "<<num<<endl;

	multimap<string, Person>::iterator it = st.find("develop");
	/*while (it->first == "develop")
	{
		cout<<it->first <<" "<<it->second.name<<" "<<it->second.age<<endl;
		it++;
	}
	*/
	int tag = 0;
	while (it->first == "develop" && tag < num)
	{
		cout<<it->first <<" "<<it->second.name<<" "<<it->second.age<<endl;
		it++;
		tag++;
	}
}

void test2()
{
	multimap<string, Person> st;
	Person p1, p2, p3, p4, p5, p6;
	p1.name = "张一";
	p1.age = 21;
	
	p2.name = "张二";
	p2.age = 22;
	
	p3.name = "张三";
	p3.age = 23;
	
	p4.name = "张四";
	p4.age = 24;
	
	p5.name = "张五";
	p5.age = 25;
	
	p6.name = "张刘";
	p6.age = 26;

	st.insert(pair<string, Person>("sale", p1));
	st.insert(pair<string, Person>("sale", p2));
	st.insert(pair<string, Person>("develop", p3));
	st.insert(pair<string, Person>("develop", p4));
	st.insert(pair<string, Person>("math", p5));

	for(multimap<string, Person>::iterator it = st.begin(); it != st.end(); it++)
	{
		if(it->second.age == 23)
		{
			it->second.name = "name23";
		}
		cout<<it->first <<" "<<it->second.name<<" "<<it->second.age<<endl;
	}
	cout<<endl;

	for(multimap<string, Person>::iterator it = st.begin(); it != st.end(); it++)
	{
		it->second = p6;
		cout<<it->first <<" "<<it->second.name<<" "<<it->second.age<<endl;
		break;
	}
}

void main()
{
	//test1();
	test2();

	system("pause");
	return;
}