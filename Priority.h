#pragma once
#include <iostream>
#include <string>;
using namespace std;

class heap
{
public:

	heap();
	heap(int array[], int size);
	~heap() { delete heapArray; };
	string printArray();
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
	string printHeap();

private:
	heap heapArray;
};


const int MAX_SIZE = 10000;

class  pQueue {
public:
	pQueue();

	void pInsert(int val);

	void pRemove();

	string printPQueue();

private:
	int last;
	int data[MAX_SIZE];
};
