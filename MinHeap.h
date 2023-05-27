#pragma once
#include "Pair.h"
#include "MaxHeap.h"
class MaxHeap;
class MinHeap
{
private:
	Pair* data;
	MaxHeap* maxHeap; //pointer to copy max heap
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
	void Delete(int i); // fun to delete pair by index
	void setMaxPointer(MaxHeap* p);
	Pair& getPairByIndex(int i); //fun to get the pair by index in the copy Max heap

};



