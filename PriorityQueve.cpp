#include "priorityQueve.h"



void priorityQueve::max()
{
	if (MaxHeapBigVals.getHeapSize() >= 1)
	{
		Pair max = MaxHeapBigVals.Max();
		cout << max.getPriority() << ' ' << max.getData() << endl;
	}
	else if (MaxHeapSmallVals.getHeapSize() >= 1)
	{
		Pair max = MaxHeapSmallVals.Max();
		cout << max.getPriority() << ' ' << max.getData() << endl;
	}
	else
		cout << "structure is empty" << endl;
}
void priorityQueve::deleteMax()
{
	if (MaxHeapBigVals.getHeapSize() < 1)
	{
		if (MaxHeapSmallVals.getHeapSize() >= 1)
		{
			Pair max = MaxHeapSmallVals.DeleteMax();
			MinHeapSmallVals.Delete(max.getIndexSecHeap());
			cout << max.getPriority() << ' ' << max.getData() <<endl;
		}
	}
	else
	{
		Pair max = MaxHeapBigVals.DeleteMax();
		MinHeapBigVals.Delete(max.getIndexSecHeap());
		cout << max.getPriority() << ' ' << max.getData() << endl;
	}
}
void priorityQueve::min()
{
	if (MinHeapSmallVals.getHeapSize() >= 1)
	{
		Pair min = MinHeapSmallVals.Min();
		cout << min.getPriority() << ' ' << min.getData() << endl;
	}
	else if (MinHeapBigVals.getHeapSize() >= 1)
	{
		Pair min = MinHeapBigVals.Min();
		cout << min.getPriority() << ' ' << min.getData() << endl;
	}
	else
		cout << "structure is empty";
}
void priorityQueve::deleteMin()
{
	if (MinHeapSmallVals.getHeapSize() >= 1)
	{
		Pair min = MinHeapSmallVals.DeleteMin();
		MaxHeapSmallVals.Delete(min.getIndexSecHeap());
		cout << min.getPriority() << ' ' << min.getData() << endl;
	}
	else if (MinHeapBigVals.getHeapSize() >= 1)
	{
		Pair min = MinHeapBigVals.DeleteMin();
		MaxHeapBigVals.Delete(min.getIndexSecHeap());
		cout << min.getPriority() << ' ' << min.getData() << endl;
	}
	else
	{
		cout << "structure is empty";
	}
}
void priorityQueve::createEmpty()
{
	MinHeapSmallVals =  MinHeap(MAX_SIZE,nullptr);
	MaxHeapSmallVals = MaxHeap(MAX_SIZE,  nullptr);
	MinHeapBigVals= MinHeap(MAX_SIZE,  nullptr);
	MaxHeapBigVals= MaxHeap(MAX_SIZE,  nullptr);
	MinHeapSmallVals.setMaxPointer(&MaxHeapSmallVals);
	MaxHeapSmallVals.setMinPointer(&MinHeapSmallVals);
	MinHeapBigVals.setMaxPointer(&MaxHeapBigVals);
	MaxHeapBigVals.setMinPointer(&MinHeapBigVals);
}
void priorityQueve::insert(int priority, string value)
{

	Pair x(priority, value, 0);
	
		if (MaxHeapSmallVals.getHeapSize()<1||priority > MaxHeapSmallVals.Max().getPriority())
		{
			 MaxHeapBigVals.insert(x);
			 MinHeapBigVals.insert(x);
			if (MaxHeapSmallVals.getHeapSize() < MaxHeapBigVals.getHeapSize())
			{
				Pair y = MinHeapBigVals.DeleteMin();
				MaxHeapBigVals.Delete(y.getIndexSecHeap());
				MaxHeapSmallVals.insert(y);
				MinHeapSmallVals.insert(y);
				
			}
		}

		else
		{
		 MaxHeapSmallVals.insert(x);
		 MinHeapSmallVals.insert(x);

			if (MaxHeapSmallVals.getHeapSize() > MaxHeapBigVals.getHeapSize() + 1)
			{
				Pair z = MaxHeapSmallVals.DeleteMax();
				MinHeapSmallVals.Delete(z.getIndexSecHeap());
				 MaxHeapBigVals.insert(z);
				 MinHeapBigVals.insert(z);
				
			}
		}
	
	


}
void priorityQueve::median()
{
	if (MaxHeapSmallVals.getHeapSize() < 1)
	{
		cout << "invalid action";
		exit(1);
	}
	Pair median = MaxHeapSmallVals.Max();
	int l = MinHeapSmallVals.getHeapSize();
	int m = MaxHeapBigVals.getHeapSize();
	int n = MinHeapBigVals.getHeapSize();
	cout << median.getPriority() << ' ' << median.getData() << endl;

}