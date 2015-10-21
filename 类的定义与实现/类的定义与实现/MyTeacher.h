#pragma once
class MyTeacher
{
public:
	MyTeacher(void);
	~MyTeacher(void);
	void setAge(int age);
	int getAge();
private:
	int m_age;
	char m_name[64];
};

