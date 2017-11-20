/*
 * hw7.h
 *
 *  Created on: Oct 22, 2017
 *      Author: andrewratz
 */

#ifndef HW7_H_
#define HW7_H_

#include <cstdio>
using namespace std;

namespace cop3530 {
	//Template of class T, standing for "element"
	template <class T>
	class ADTHeap {
	public:
		T* start;
		T* end;
		//For removal
		T* backing_array;;
		ADTHeap(T* start, T* end, int n) {
			this->start = start;
			this->end = end;
			backing_array = new T[n];
		}
		~ADTHeap() {

		}
		//Returns the size of the heap's array
		size_t size() {
			size_t n = 0;
			T* temp_start = start;
			T* temp_end = end;
			while (temp_start != temp_end) {
				n++;
				temp_start++;
			}
			return n;
		}
		//Prints the heap
		void print() {
			T* temp_start = start;
			T* temp_end = end;
			temp_start++;
			temp_end++;
			while (temp_start != temp_end) {
				cout << *temp_start << " ";
				temp_start++;
			}
			cout << endl;
			return;
		}
		//Heapifies the passed in array
		void min_heapify() {
			int i = size()/2;
			min_top_down_fix(i);
			--i;
			while (i != 0) {
				min_top_down_fix(i);
				--i;
			}
			return;
		}
		//Compares the parent to its children
		void min_top_down_fix(int i) {
			if (start[i] > start[2*i] && start[2*i] <= start[(2*i)+1]) {
				T temp = start[2*i];
				start[2*i] = start[i];
				start[i] = temp;
				min_top_down_fix(2*i);
			}
			if (2*i == size()) {
				if (start[i] > start[2*i]) {
					T temp = start[2*i];
					start[2*i] = start[i];
					start[i] = temp;	
				}
				return;
			}
			else if (start[i] > start[(2*i)+1] && start[(2*i)+1] <= start[2*i]) {
				T temp = start[(2*i)+1];
				start[(2*i)+1] = start[i];
				start[i] = temp;
				min_top_down_fix((2*i)+1);
			}
			return;
		}
		void min_bottom_up_fix(int i) {
			if (start[i/2] > start[i]) {
				T temp = start[i];
				start[i] = start[i/2];
				start[i/2] = temp;
				min_bottom_up_fix(i/2);
			}
			return;		
		}
		void min_insert(T element) {
			end++;
			*end = element;
			int i = size();
			min_bottom_up_fix(i);
		}
		void min_remove(T element) {
			T* temp_start = start;
			T* temp_end = end;
			bool done = false;
			int n = size();
			for (int i = 0; i < n; i++) {
				if (*temp_start == element && done == false) {
					i--;
					temp_start++;
					done = true;
					continue;
				}
				else {
					backing_array[i] = *temp_start;
					temp_start++;
				}
			}
			start = &backing_array[0];
			end = &backing_array[n-1];
			min_heapify();
		}
		//Heapifies the passed in array
		void max_heapify() {
			int i = size()/2;
			max_top_down_fix(i);
			--i;
			while (i != 0) {
				max_top_down_fix(i);
				--i;
			}
			return;
		}
		//Compares the parent to its children
		void max_top_down_fix(int i) {
			if (2*i >= size()) {
				return;
			}
			if (start[i] < start[2*i] && start[2*i] >= start[(2*i)+1]) {
				T temp = start[2*i];
				start[2*i] = start[i];
				start[i] = temp;
				max_top_down_fix(2*i);
			}
			else if (start[i] < start[(2*i)+1] && start[(2*i)+1] >= start[2*i]) {
				T temp = start[(2*i)+1];
				start[(2*i)+1] = start[i];
				start[i] = temp;
				max_top_down_fix((2*i)+1);
			}
			return;
		}
		void max_bottom_up_fix(int i) {
			if (start[i/2] < start[i]) {
				T temp = start[i];
				start[i] = start[i/2];
				start[i/2] = temp;
				max_bottom_up_fix(i/2);
			}
			return;		
		}
		void max_insert(T element) {
			end++;
			*end = element;
			int i = size();
			max_bottom_up_fix(i);
		}
		void max_remove(T element) {
			T* temp_start = start;
			T* temp_end = end;
			bool done = false;
			int n = size();
			for (int i = 0; i < n; i++) {
				if (*temp_start == element && done == false) {
					i--;
					temp_start++;
					done = true;
					continue;
				}
				else {
					backing_array[i] = *temp_start;
					temp_start++;
				}
			}
			start = &backing_array[0];
			end = &backing_array[n-1];
			max_heapify();
		}
		void sort() {
			int n = size();
			T* temp_start = start;
			temp_start++;
			max_heapify();
			while (true) {
				T element = *temp_start;
				if (size() == 2) {
					print();
					break;
				}
				cout << element << " ";
				max_remove(element);
			}
			return;
		}
	};

}

#endif /* HW7_H_ */
