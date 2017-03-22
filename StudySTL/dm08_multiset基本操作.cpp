#include <iostream>
#include "set"
using namespace std;

void test1()
{
	multiset<int> st;
	cout<<"大小："<<st.size()<<endl;
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

	set<int>::iterator it1 = st.lower_bound(5);   //大于等于5的迭代器的位置
	cout<<"大于等于："<<*it1<<endl;
	set<int>::iterator it2 = st.upper_bound(5);   //大于5的迭代器的位置
	cout<<"大于："<<*it2<<endl;
	
	st.erase(5);
	 //返回等于5和大于5的迭代器的位置
	pair<set<int>::iterator, set<int>::iterator> pair1 = st.equal_range(5); 
	cout<<*pair1.first<<" "<<*pair1.second<<endl;

}

void main()
{
	test1();

	system("pause");
	return;
}