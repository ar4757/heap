/*
 * hw7.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: andrewratz
 */

#include <iostream>
#include "hw7.h"

using namespace std;
using namespace cop3530;

int main() {
	cout << "---MAX HEAP TESTING---" << endl;
	//The first element is null
	int scores2[] = {0, 6, 3, 9, 11, 14, 22, 12, 1, 6, 5};
	int* start2 = &scores2[0];
	int* end2 = &scores2[10];
	ADTHeap<int>* int_Heap2 = new ADTHeap<int>(start2, end2, 10);
	cout << "The starting array: ";
	int_Heap2->print();
	cout << endl;
	cout << "The size of the array: ";
	cout << int_Heap2->size() << endl;
	cout << endl;
	int_Heap2->max_heapify();
	cout << "Max-heapified array: ";
	int_Heap2->print();
	cout << endl;
	cout << "Max-heapified array with newly inserted 2: ";
	int_Heap2->max_insert(2);
	int_Heap2->print();
	cout << endl;
	cout << "Max-heapified array with removed 2: ";
	int_Heap2->max_remove(2);
	int_Heap2->print();
	cout << endl;
	cout << "Sorted array using heapsort: ";
	int_Heap2->sort();
	cout << endl;

	cout << "---MIN HEAP TESTING---" << endl;
	//The first element is null
	int scores[] = {0, 3, 2, 4, 1, 5};
	int* start = &scores[0];
	int* end = &scores[5];
	ADTHeap<int>* int_Heap = new ADTHeap<int>(start, end, 5);
	cout << "The starting array: ";
	int_Heap->print();
	cout << endl;
	cout << "The size of the array: ";
	cout << int_Heap->size() << endl;
	cout << endl;
	int_Heap->min_heapify();
	cout << "Min-heapified array: ";
	int_Heap->print();
	cout << endl;
	int_Heap->min_remove(2);
	int_Heap->print();
	cout << endl;
	cout << "Sorted array using heapsort: ";
	int_Heap->sort();
	cout << endl;
}























