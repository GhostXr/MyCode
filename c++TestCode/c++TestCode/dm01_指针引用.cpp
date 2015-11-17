#include "iostream"

using namespace std;

struct Teacher
{
	int age;
	char name[64];
};

//二级指针
int getTeacher(Teacher **pT)
{
	Teacher *temp = NULL;
	if (pT == NULL)
	{
		return -1;
	}

	temp = (Teacher *)malloc(sizeof(Teacher));
	if (temp == NULL)
	{
		return -2;
	}
	temp->age = 26;
	strcpy(temp->name, "Ghost");
	*pT = temp;
	return 0;
}

//指针引用
int getTeacher2(Teacher *&pT)
{
	if (pT == NULL)
	{
		return -1;
	}
	pT = (Teacher *)malloc(sizeof(Teacher));
	if (pT == NULL)
	{
		return -2;
	}
	pT->age = 27;
	strcpy(pT->name, "Ghost2");
	return 0;
}


int freeTeacher(Teacher *pT)
{
	if (pT == NULL)
	{
		return -1;
	}
	free(pT);
	return 0;
}

int main01()
{
	Teacher *pT = NULL;
	int ret = 0;

	ret = getTeacher(&pT);
	if (ret != 0)
	{
		cout<<"func getTeacher is error:"<<ret<<endl;
	}
	cout<<"pT->age == "<<pT->age<<endl;
	cout<<"pT->name == "<<pT->name<<endl;

	ret = freeTeacher(pT);
	if (ret != 0)
	{
		cout<<"func freeTeacher is error:"<<ret<<endl;
	}
	
	ret = getTeacher2(pT);
	if (ret != 0)
	{
		cout<<"func getTeacher is error:"<<ret<<endl;
	}
	cout<<"pT->age == "<<pT->age<<endl;
	cout<<"pT->name == "<<pT->name<<endl;
	
	ret = freeTeacher(pT);
	if (ret != 0)
	{
		cout<<"func freeTeacher is error:"<<ret<<endl;
	}
	system("pause");
	return 0;
}