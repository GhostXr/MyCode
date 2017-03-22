#include <iostream>
#include "set"
using namespace std;

void test1()
{
	multiset<int> st;
	cout<<"��С��"<<st.size()<<endl;
	for(int i = 0; i < 10; i++)
	{
		int temp = rand();
		st.insert(temp);
	}
	st.insert(100);
	st.insert(100);
	st.insert(100);

	for(set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	set<int>::iterator it1 = st.lower_bound(5);   //���ڵ���5�ĵ�������λ��
	cout<<"���ڵ��ڣ�"<<*it1<<endl;
	set<int>::iterator it2 = st.upper_bound(5);   //����5�ĵ�������λ��
	cout<<"���ڣ�"<<*it2<<endl;
	
	st.erase(5);
	 //���ص���5�ʹ���5�ĵ�������λ��
	pair<set<int>::iterator, set<int>::iterator> pair1 = st.equal_range(5); 
	cout<<*pair1.first<<" "<<*pair1.second<<endl;

}

void main()
{
	test1();

	system("pause");
	return;
}