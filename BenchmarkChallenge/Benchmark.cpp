#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include "WalkingArray.h"
using namespace std;
using namespace std::chrono;

//Thomas Klaesges

int main() {
	//Make a queue, DOES NOT HAVE A SHADOW ARRAY
	WalkingArray<int> queue;

	//Adds elements to the queue until just before array expansion is required
	for (int i = 0; i < 268435454; i++) {
		queue.enqueue(i);
	}
	auto start = high_resolution_clock::now();

	queue.enqueue(101010);

	auto end = high_resolution_clock::now();

	//
	auto duration = duration_cast<microseconds>(end - start);

	cout << "Time elapsed for one enqueue: "  << duration.count() 
		<< " seconds" << endl << endl;

	auto start1 = high_resolution_clock::now();

	queue.enqueue(1);

	auto end1 = high_resolution_clock::now();

	auto duration1 = duration_cast<microseconds>(end1 - start1);

	cout << "Time elapsed for one enqueue: " << duration.count() 
		<< " seconds" << endl << endl;

	auto start2 = high_resolution_clock::now();

	queue.enqueue(1);

	auto end2 = high_resolution_clock::now();

	auto duration2 = duration_cast<microseconds>(end2 - start2);

	cout << "Time elapsed for one enqueue with array expansion: " << (duration2.count() * 0.000001) 
		<< " seconds" << endl << endl;


	cout << "Enqueueing done." << endl;	
}