#include "MinHeap.h"
MinHeap::MinHeap(const MinHeap& other)
{
	if (allocated==1)
		delete[]data;
	
	maxSize = other.maxSize;
	HeapSize = other.HeapSize;
	allocated = 1;
	data = new Pair[maxSize];
	for (int i = 0; i < HeapSize; i++)
		data[i] = other.data[i];
}
MinHeap& MinHeap::operator=(const MinHeap& other)
{
	if (this != &other)
	{
		if(allocated==1)
			delete[] data;
		maxSize = other.maxSize;
		HeapSize = other.HeapSize;
		allocated = 1;
		data = new Pair[maxSize];
		for (int i = 0; i < HeapSize; i++)
			data[i] = other.data[i];
	}
	return *this;
}
MinHeap::MinHeap(int max,MaxHeap * maxP)
{
	data = new Pair[max];
	maxSize = max;
	HeapSize = 0;
	allocated = 1;
	maxHeap = maxP;
}
MinHeap::~MinHeap()
{
	if (allocated==1)
	{
		delete[] data;

		allocated = 0;
	}
}

Pair MinHeap::Min()
{
	if(HeapSize>=1)
	return data[0];
	else {
		cout << "invalid action";
		exit(1);
	}
}
int MinHeap::Parent(int node)
{
	return (node - 1) / 2;
}
int MinHeap::Left(int node)
{
	return 2 * node + 1;
}
int MinHeap::Right(int node)
{
	return 2 * node + 2;
}
void MinHeap::FixMinHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);
	if ((left < HeapSize) && (data[left].getPriority() < data[node].getPriority()))
		min = left;
	else
		min = node;
	if ((right < HeapSize) && (data[right].getPriority() < data[min].getPriority()))
		min = right;

	if (min != node)
	{
		//update index saver in the copy Max heap
		(*maxHeap).getPairByIndex(data[node].getIndexSecHeap()).setIndexSecHeap(min); 
		(*maxHeap).getPairByIndex(data[min].getIndexSecHeap()).setIndexSecHeap(node);
		swap(&(data[node]), &(data[min]));
		
		FixMinHeap(min);
	}

}
Pair MinHeap::DeleteMin()
{
	if (HeapSize < 1)
	{
		throw std::runtime_error("Error: MinHeap is empty!");
	}

	Pair min = data[0];
	

	if (HeapSize == 1)
	{
		HeapSize--;
		return min;
	}

	(*maxHeap).getPairByIndex(data[HeapSize - 1].getIndexSecHeap()).setIndexSecHeap(0);
	data[0] = data[HeapSize - 1];

	HeapSize--;
	FixMinHeap(0);

	return min;
}
int MinHeap::insert(Pair& item)
{
	
	if (HeapSize == maxSize)
	{
		cout << "invalid action";
		exit(1);
	}
	int i = HeapSize;
	HeapSize++;
	while ((i > 0) && (data[Parent(i)].getPriority() > item.getPriority()))
	{
		data[i] = data[Parent(i)];
		int parentIndexSecHeap = data[Parent(i)].getIndexSecHeap();
		//update index saver in the copy Max heap
		(*maxHeap).getPairByIndex(parentIndexSecHeap).setIndexSecHeap(i);
		i = Parent(i);
	}
	data[i] = item;
	//update index saver in the copy Max heap
	(*maxHeap).getPairByIndex(item.getIndexSecHeap()).setIndexSecHeap(i);
	item.setIndexSecHeap(i);
	
	return i;
}
int MinHeap::getHeapSize()
{
	return HeapSize;
}
void MinHeap:: setMaxPointer(MaxHeap* p)
{
	maxHeap = p;
}
void MinHeap::Delete(int i)
{
	if (HeapSize < 1) {
		throw std::runtime_error("Error: MaxHeap is empty!");
	}

	int lastIndex = HeapSize - 1;
	

	if (i != lastIndex)
	{
		//update index saver in the copy Max heap
		(*maxHeap).getPairByIndex(data[i].getIndexSecHeap()).setIndexSecHeap(lastIndex);
		(*maxHeap).getPairByIndex(data[lastIndex].getIndexSecHeap()).setIndexSecHeap(i);
		swap(&data[i], &data[lastIndex]);
		FixMinHeap(i);
	}

	HeapSize--;
}
Pair& MinHeap::getPairByIndex(int i) {
	return data[i];
}
