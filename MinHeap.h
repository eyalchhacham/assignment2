#pragma once
#include "Pair.h"
#include "MaxHeap.h"
class MaxHeap;
class MinHeap
{
private:
	Pair* data;
	MaxHeap* maxHeap;
	int maxSize;
	int HeapSize;
	int allocated;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	
public:
	MinHeap() {};
	MinHeap(int max,MaxHeap* maxP);
	void FixMinHeap(int node);
	MinHeap(const MinHeap& other);
	MinHeap& operator=(const MinHeap& other);
	~MinHeap();
	Pair Min();
	Pair DeleteMin();
	int insert(Pair& item);
	int getHeapSize();
	void Delete(int i);
	void setMaxPointer(MaxHeap* p);
	Pair& getPairByIndex(int i);

};



