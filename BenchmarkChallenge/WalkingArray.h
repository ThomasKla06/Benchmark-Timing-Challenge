#pragma once

template<typename T>
class WalkingArray {

private:
	int size;
	int capacity;
	T* data;
	T* front;
	T* rear;

public:
	WalkingArray() {
		size = 0;
		capacity = 16;
		data = new T[capacity];
		front = &data[0];
		rear = &data[0];
	}

	//Copy constructor
	WalkingArray(const WalkingArray<T>& other) {
		size = other.size;
		capacity = other.capacity;
		data = new T[capacity];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
		front = data[0];
		rear = data[size];
	}
	//Destructor
	~WalkingArray() {
		delete[] data;
	}
	//Copy Assignment Operator Overload
	WalkingArray<T>& operator=(const WalkingArray<T> other) {
		delete[] data;

		capacity = other.capacity;
		size = other.size;
		data = new T[capacity];

		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}

		return *this;
	}

	T peek() {
		return *front;
	}

	void dequeue() {
		if (front != rear) {
			front++;
			--size;
		}
	}

	void enqueue(T val) {
		if (size == capacity) {
			capacity *= 2;
			T* tmp = new T[capacity];
			for (int i = 0; i < size; i++)
				tmp[i] = data[i];
			delete[] data;
			data = tmp;
		}
		data[size] = val;
		rear++;
		size++;
	}
	int length() { return size; }
	bool isEmpty() { return size == 0; }
};