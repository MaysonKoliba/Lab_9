#include "Priority.h"
#include <string>
#include <iostream>
using namespace std;

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

void heap::printArray()
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

	for (int i = 0; i < itemCount; i++) {
		cout << to_string(heapArray[i]) + " ";
	}
};

bool heap::remove()
{
	heapArray[0] = heapArray[itemCount - 1];
	itemCount--;
	heapRebuild(0);
	return true;
};

bool heap::add(const int& data)
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


bool priorityQueueHeap::add(const int& data)
{
	return heapArray.add(data);
}

bool priorityQueueHeap::remove()
{
	return heapArray.remove();
}

void priorityQueueHeap::printHeap()
{
	return heapArray.printArray();
}
