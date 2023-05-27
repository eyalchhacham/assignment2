#pragma once
#include "Pair.h"
#include "MinHeap.h"
class MinHeap;
class MaxHeap
{
private:
	Pair* data;
	MinHeap* minHeap; //pointer to copy min Heap
	int maxSize;
	int HeapSize;
	int allocated;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);

public:
	MaxHeap& operator=(const MaxHeap& other);
	MaxHeap(const MaxHeap& other);
	void FixMaxHeap(int node);
	MaxHeap() {};
	MaxHeap(int max,MinHeap* minP);
	~MaxHeap();
	Pair Max();
	Pair DeleteMax();
	int insert(Pair& item);
	int getHeapSize();
	void Delete(int i); //fun to delete pair by index
	void setMinPointer(MinHeap* p);
	Pair& getPairByIndex(int i); //fun to get pair from copy min heap

};


