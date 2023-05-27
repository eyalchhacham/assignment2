#pragma once

#include <iostream>
#include<string>
using namespace std;


class Pair
{
private:

	int priority;
	string data;
	int indexSecHeap;
public:

	Pair() {};
	Pair(const Pair& other);
	Pair(int p, string d, int i);
	int getPriority();
	string getData();
	int getIndexSecHeap();
	void setIndexSecHeap(int i);

	
};
void swap(Pair* a, Pair* b);

