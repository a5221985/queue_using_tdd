/*
 * Foo.h
 *
 *  Created on: 08-Aug-2020
 *      Author: am
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdexcept>

template<typename T, uint32_t N>
class Queue {
public:
	Queue() {
		static_assert(N > 0, "Initial size must be > 0");
		this->items = new T[size];
	}

	~Queue() {
		delete[] items;
	}

	bool isEmpty(void) {
		return tail == -1;
	}

	void enqueue(T item) {
		if (isFull())
			resize();
		advanceTail();
		this->items[tail] = item;
		if (head == -1)
			head = tail;
	}

	T dequeue(void) {
		if (isEmpty())
			throw std::out_of_range("Out of range");
		int item = items[head];
		if (isLastItem())
			reset();
		else
			advanceHead();
		return item;
	}

	void resize(void) {
		int newSize = 2 * size;
		T *newItems = new T[newSize];
		int k = 0;
		while (!isLastItem()) {
			newItems[k++] = items[head];
			advanceHead();
		}
		newItems[k] = items[head];
		delete[] items;
		items = newItems;
		head = 0;
		tail = k;
		size = newSize;
	}

private:
	int head = -1;
	int tail = -1;
	int size = N;
	T *items;

	bool isFull(void) {
		return tail != -1 && (tail + 1) % size == head;
	}

	bool isLastItem(void) {
		return tail != -1 && head == tail;
	}

	void reset() {
		tail = -1;
		head = -1;
	}

	void advanceHead(void) {
		head = (head + 1) % size;
	}

	void advanceTail(void) {
		tail = (tail + 1) % size;
	}
};

#endif /* QUEUE_H_ */
