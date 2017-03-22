#include "iostream"

using namespace std;

class Singer
{
private:
	Singer()
	{
		cout<<"我是构造函数"<<endl;
	}
public:
 	static Singer* getInstance()
	{
		if (singer == NULL)
		{
			singer = new Singer();
		}
		return singer;
	}
private:
	static Singer *singer;
};

Singer *Singer::singer;

void main()
{
	Singer* singer1 = Singer::getInstance();
	Singer* singer2 = Singer::getInstance();

	if (singer1 == singer2)
	{
		cout<<"是同一个对象"<<endl;
	}
	delete singer1;

	system("pause");
	return;
}