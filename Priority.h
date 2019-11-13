#pragma once
#include <iostream>
#include <string>;
using namespace std;

//We used our text book to help us with many of the functions in the heap class 
//such as heapRebuild, heapCreate, add, and remove.

//Heap Class
class heap
{
public:

	//default constructor
	heap();
	//overloaded constructor
	heap(int array[], int size);
	//deconstructor
	~heap() { delete heapArray; };
	//prints the array in priority order
	string printArray();
	//adds an element to the heap
	bool add(int data);
	//removes the largest elements from the heap
	bool remove();

private:

	//returns an index to the left child of the selected node
	int getLeftChild(int index) { return (2 * index) + 1; };
	//returns an index to the right child of the selected node
	int getRightChild(int index) { return (2 * index) + 2; };
	//returns an index to the parent of the selected node
	int getParent(int index) { return ((index - 1) / 2); };
	//reorders the tree to get it in the correct format after a node is added or removed
	void heapRebuild(int root);
	//creates the heap structure
	void heapCreate();

	int* heapArray;
	int itemCount;
	int maxItems;
};


//Heap implementation of the priority queue, (uses the heap class)
class priorityQueueHeap
{
public:

	//constructor
	priorityQueueHeap() {};
	//deconstructor
	~priorityQueueHeap() {};
	//adds an element to the priority queue
	bool add(int data);
	//removes the largest element in the priority queue
	bool remove();
	//prints the heap in priority order
	string printHeap();

private:
	heap heapArray;
};


// Array/Queue implementation of a priority queue
const int MAX_SIZE = 10000;

class  pQueue {
public:

	//constructor
	pQueue();
	//inserts an item into the queue
	void pInsert(int val);
	//removes an item from the queue
	void pRemove();
	//prints the queue in priority order
	string printPQueue();

private:
	int last;
	int data[MAX_SIZE];
};
