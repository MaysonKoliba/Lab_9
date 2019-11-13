#include "..\\Lab_9\Priority.h"
#include <string>
#include <iostream>
using namespace std;

//////   Heap class functions   //////
heap::heap()
{
	itemCount = 0;
	maxItems = 10000;
	heapArray = new int[maxItems];

};

heap::heap(int array[], int size) : itemCount(size), maxItems(2 * size)
{
	heapArray = new int[maxItems];

	for (int i = 0; i < size; i++) {
		heapArray[i] = array[i];
	}

	heapCreate();
};

void heap::heapRebuild(int root)

{
	int size = itemCount;
	int largest = root;
	int left = getLeftChild(root);
	int right = getRightChild(root);

	if (left < size && heapArray[left] > heapArray[largest]) {
		largest = left;
	}

	if (right < size && heapArray[right] > heapArray[largest]) {
		largest = right;
	}

	if (largest != root) {
		swap(heapArray[root], heapArray[largest]);

		heapRebuild(largest);
	}
};

void heap::heapCreate()
{
	for (int i = itemCount / 2; i >= 0; i--) {
		heapRebuild(i);
	}
};

string heap::printArray()
{
	for (int i = itemCount / 2; i >= 0; i-- ) {

		heapRebuild(i);
	}

	swap(heapArray[0], heapArray[itemCount - 1]);

	int temp = itemCount;
	int heapSize = itemCount - 1;

	while (heapSize > 1) {

		itemCount = heapSize;
		heapRebuild(0);
		swap(heapArray[0], heapArray[heapSize - 1]);
		heapSize--;
	}

	itemCount = temp;
	string output = "";

	for (int i = 0; i < itemCount; i++) {
		output = output + to_string(heapArray[i]);
	}

	return output;
};

bool heap::remove()
{
	heapArray[0] = heapArray[itemCount - 1];
	itemCount--;
	heapRebuild(0);
	return true;
};

bool heap::add(int data)
{
	heapArray[itemCount] = data;

	int newDataIndex = itemCount;
	bool inPlace = false;

	while ((newDataIndex >= 0) && !inPlace) {
		int parentIndex = (newDataIndex - 1) / 2;
		if (heapArray[newDataIndex] <= heapArray[parentIndex]) {
			inPlace = true;
		}
		else {
			swap(heapArray[newDataIndex], heapArray[parentIndex]);
			newDataIndex = parentIndex;
		}
	}
	itemCount++;

	return true;
};


////   Priority queue using a heap functions   /////
bool priorityQueueHeap::add(int data)
{
	return heapArray.add(data);
}

bool priorityQueueHeap::remove()
{
	return heapArray.remove();
}

string priorityQueueHeap::printHeap()
{
	
	return heapArray.printArray();
}


///////    Priority queue using an array/queue functions   ///////

pQueue::pQueue() {
	last = -1;
}

void pQueue::pInsert(int val) {
	int temp;
	if (last == -1) {
		data[0] = val;
	}
	else if (last == 0) {
		if (val < data[0]) {
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


void pQueue::pRemove() {
	data[last] = 0;
	last--;
}

string pQueue::printPQueue()
{
	string output = "";

	for (int i = 0; i < last + 1; i++) {
		output = output + to_string(data[i]);
	}

	return output;
}
