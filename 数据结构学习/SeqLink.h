#pragma once

template <typename T>
class SeqLink
{
public:
	SeqLink(int num);
	~SeqLink();

	int getLength();

	int getCapacity();

	int insert(T &node, int pos);

	int getNode(T &t, int pos);

	void deleteNode(int pos);

private:
	int length;
	int capacity;
	T *pArray;
};


