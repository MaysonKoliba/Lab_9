// Lab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Priority.h"
#include <ctime>
#include "stdlib.h"
#include "time.h"
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;

int main()
{
	priorityQueueHeap test500;
	priorityQueueHeap test1000;
	priorityQueueHeap test2000;
	priorityQueueHeap test5000;

	pQueue queue500;
	pQueue queue1000;
	pQueue queue2000;
	pQueue queue5000;


	int array500[500];
	int array1000[1000];
	int array2000[2000];
	int array5000[5000];

	for (int i = 0; i < 500; i++) {
		int randNum = rand() % 500;
		array500[i] = randNum;
	}

	for (int i = 0; i < 1000; i++) {
		int randNum = rand() % 1000;
		array1000[i] = randNum;
	}

	for (int i = 0; i < 2000; i++) {
		int randNum = rand() % 2000;
		array2000[i] = randNum;
	}

	for (int i = 0; i < 5000; i++) {
		int randNum = rand() % 5000;
		array5000[i] = randNum;
	}

	auto t1 = Clock::now();
	for (int i = 0; i < 500; i++) {test500.add(array500[i]);}
	auto t2 = Clock::now();

	cout << "heap500 Heap: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
		<< " nanoseconds" << std::endl;


	auto t3 = Clock::now();
	for (int i = 0; i < 1000; i++) {test1000.add(array1000[i]);}
	auto t4 = Clock::now();

	cout << "heap1000 Heap: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count()
		<< " nanoseconds" << std::endl;


	auto t5 = Clock::now();
	for (int i = 0; i < 2000; i++) {test2000.add(array2000[i]);}
	auto t6 = Clock::now();

	cout << "heap2000 Heap: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t6 - t5).count()
		<< " nanoseconds" << std::endl;


	auto t7 = Clock::now();
	for (int i = 0; i < 5000; i++) {test5000.add(array5000[i]);}
	auto t8 = Clock::now();

	cout << "heap5000 Heap: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t8 - t7).count()
		<< " nanoseconds" << std::endl;

	///////////////////////////////////////////////////////////////////

	auto t9 = Clock::now();
	for (int i = 0; i < 500; i++) { queue500.pInsert(array500[i]); }
	auto t10 = Clock::now();

	cout << "queue500 Heap: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t10 - t9).count()
		<< " nanoseconds" << std::endl;


	auto t11 = Clock::now();
	for (int i = 0; i < 1000; i++) { queue1000.pInsert(array1000[i]); }
	auto t12 = Clock::now();

	cout << "queue1000 Heap: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t12 - t11).count()
		<< " nanoseconds" << std::endl;


	auto t13 = Clock::now();
	for (int i = 0; i < 2000; i++) { queue2000.pInsert(array2000[i]); }
	auto t14 = Clock::now();

	cout << "queue2000 Heap: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t14 - t13).count()
		<< " nanoseconds" << std::endl;


	auto t15 = Clock::now();
	for (int i = 0; i < 5000; i++) { queue5000.pInsert(array5000[i]); }
	auto t16 = Clock::now();

	cout << "queue5000 Heap: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t16 - t15).count()
		<< " nanoseconds" << std::endl;

	return 0;
};
