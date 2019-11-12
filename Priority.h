#pragma once
#include <iostream>

class heap
{
public:

	heap();
	heap(int array[], int size);
	~heap() { delete heapArray; };
	void printArray();
	bool add(const int& data);
	bool remove();


private:

	int getLeftChild(int index) { return (2 * index) + 1; };
	int getRightChild(int index) { return (2 * index) + 2; };
	int getParent(int index) { return ((index - 1) / 2); };
	void heapRebuild(int root);
	void heapCreate();

	int* heapArray;
	int itemCount;
	int maxItems;
};


class priorityQueueHeap
{

public:

	priorityQueueHeap() {};
	~priorityQueueHeap() {};
	bool add(const int& data);
	bool remove();
	void printHeap();

private:
	heap heapArray;
};


const int MAX_SIZE = 10000;

class  pQueue {
public:
	pQueue() {
		last = -1;
	}

	void pInsert(int val) {
		int temp;
		if (last == -1) {
			data[0] = val;
		}
		else if (last == 0) {
			if (val > data[0]) {
				temp = data[0];
				data[0] = val;
				data[1] = temp;
			}
			else {
				data[1] = val;
			}
		}
		else {
			for (int i = 0; i <= last; i++) {
				if (val < data[i]) {
					for (int j = last + 1; j > i; j--) {
						data[j] = data[j - 1];
					}
					data[i] = val;
					last++;
					return;
				}

			}
			data[last + 1] = val;
		}
		last++;
	}
	void pRemove() {
		last--;

	}
	void printPQueue() {
		for (int i = 0; i < last + 1; i++) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl << last;
	}
private:
	int last;
	int data[MAX_SIZE];
};
