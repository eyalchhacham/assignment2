#include "MaxHeap.h"
MaxHeap::MaxHeap(const MaxHeap& other)
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
MaxHeap& MaxHeap::operator=(const MaxHeap& other)
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
void MaxHeap::setMinPointer(MinHeap* p)
{
	minHeap = p;
}
MaxHeap::MaxHeap(int max,MinHeap* minP)
{
	data = new Pair[max];
	maxSize = max;
	HeapSize = 0;
	allocated = 1;
	minHeap = minP;
}
MaxHeap::~MaxHeap()
{

	if (allocated==1)
		delete[] data;
	allocated = 0;
	
}
Pair MaxHeap::Max()
{
	if (HeapSize >= 1)
		return data[0];
	else
	{
		cout << "invalid action";
		exit(1);
	}
}
int MaxHeap::Parent(int node)
{
	return (node - 1) / 2;
}
int MaxHeap::Left(int node)
{
	return 2 * node + 1;
}
int MaxHeap::Right(int node)
{
	return 2 * node + 2;
}
void MaxHeap::FixMaxHeap(int node)
{
	int max;
	int left = Left(node);
	int right = Right(node);
	if ((left < HeapSize) && (data[left].getPriority() > data[node].getPriority()))
		max = left;
	else
		max = node;
	if ((right < HeapSize) && (data[right].getPriority() > data[max].getPriority()))
		max = right;

	if (max != node)
	{
		(*minHeap).getPairByIndex(data[node].getIndexSecHeap()).setIndexSecHeap(max);
		(*minHeap).getPairByIndex(data[max].getIndexSecHeap()).setIndexSecHeap(node);
		swap(&data[node], &data[max]);
		

		FixMaxHeap(max);
	}

}
Pair MaxHeap::DeleteMax()
{
	if (HeapSize < 1)
	{
		throw std::runtime_error("Error: MaxHeap is empty!");
	}

	Pair max = data[0];
	(*minHeap).getPairByIndex(max.getIndexSecHeap()).setIndexSecHeap(-1);

	if (HeapSize == 1)
	{
		HeapSize--;
		return max;
	}

	(*minHeap).getPairByIndex(data[HeapSize - 1].getIndexSecHeap()).setIndexSecHeap(0);
	data[0] = data[HeapSize - 1];
	

	HeapSize--;
	FixMaxHeap(0);

	return max;
}
int MaxHeap::insert(Pair& item)
{
	
	if (HeapSize == maxSize)
	{
		cout << "invalid action";
		exit(1);
	}
	int i = HeapSize;
	HeapSize++;
	while ((i > 0) && (data[Parent(i)].getPriority() < item.getPriority()))
	{
		data[i] = data[Parent(i)];
		int parentIndexSecHeap = data[Parent(i)].getIndexSecHeap();
		(*minHeap).getPairByIndex(parentIndexSecHeap).setIndexSecHeap(i);
		i = Parent(i);
	}
	data[i] = item;
	item.setIndexSecHeap(i);
	return i;
}
int MaxHeap::getHeapSize()
{
	return HeapSize;
}
void MaxHeap::Delete(int i)
{
	if (HeapSize < 1) {
		throw std::runtime_error("Error: MaxHeap is empty!");
	}

	int lastIndex = HeapSize - 1;
	

	if (i != lastIndex)
	{
		(*minHeap).getPairByIndex(data[i].getIndexSecHeap()).setIndexSecHeap(lastIndex);
		(*minHeap).getPairByIndex(data[lastIndex].getIndexSecHeap()).setIndexSecHeap(i);
		swap(&data[i], &data[lastIndex]);
		FixMaxHeap(i);
	}

	HeapSize--;
}

Pair& MaxHeap::getPairByIndex(int i)
{
	return data[i];
}

