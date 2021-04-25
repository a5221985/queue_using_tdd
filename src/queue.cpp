/*
 * Foo.cpp
 *
 *  Created on: 08-Aug-2020
 *      Author: am
 */

#include <stdexcept>
#include "queue.h"

Queue::Queue(int size) {
	this->items = new int[size];
	this->size = size;
}

Queue::~Queue() {
	delete[] items;
}

void Queue::enqueue(int item) {
	if (isFull())
		resize();
	advanceTail();
	this->items[tail] = item;
	if (head == -1)
		head = tail;
}

void Queue::advanceHead() {
	head = (head + 1) % size;
}

void Queue::advanceTail() {
	tail = (tail + 1) % size;
}

int Queue::dequeue(void) {
	if (isEmpty())
		throw std::out_of_range("Out of range");
	int item = items[head];
	if (isLastItem())
		reset();
	else
		advanceHead();
	return item;
}

bool Queue::isEmpty(void) {
	return tail == -1;
}

bool Queue::isFull() {
	return tail != -1 && (tail + 1) % size == head;
}

bool Queue::isLastItem() {
	return tail != -1 && head == tail;
}

void Queue::reset() {
	tail = -1;
	head = -1;
}

void Queue::resize(void) {
	int newSize = 2 * size;
	int *newItems = new int[newSize];
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
