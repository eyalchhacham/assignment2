#pragma once

#include "MaxHeap.h"
#include "MinHeap.h"
const int MAX_SIZE = 100;
class priorityQueve
{
private:
	MinHeap MinHeapSmallVals;
	MaxHeap MaxHeapSmallVals;
	MinHeap MinHeapBigVals;
	MaxHeap MaxHeapBigVals;
public:
	priorityQueve() {};
	void max();
	void deleteMax();
	void min();
	void deleteMin();
	void createEmpty();
	void insert(int priority, string value);
	void median();
	void SmallToBIg();
	void BigToSmall();
	

};
