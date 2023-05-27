#include "Pair.h"

Pair::Pair(int p, string d, int i) :priority(p), data(d), indexSecHeap(i) {};
 Pair::Pair(const Pair& other) {
	priority = other.priority;
	data = other.data;
	indexSecHeap = other.indexSecHeap;
}
 int Pair:: getPriority()
 {
	 return priority;
 }
 string Pair::getData()
 {
	 return data;
 }
 int Pair::getIndexSecHeap()
 {
	 return indexSecHeap;
 }
 void Pair::setIndexSecHeap(int i)
 {
	 indexSecHeap = i;
 }
 void swap(Pair* a, Pair* b)
 {
	 Pair temp = *a;
	 *a = *b;
	 *b = temp;

 }
 