/*
 * Foo.h
 *
 *  Created on: 08-Aug-2020
 *      Author: am
 */

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
public:
	virtual ~Queue();
	Queue(int size);
	bool isEmpty(void);
	void enqueue(int item);
	int dequeue(void);
	void resize(void);
private:
	int head = -1;
	int tail = -1;
	int size = 0;
	int *items;

	bool isFull(void);
	bool isLastItem(void);
	void reset();
	void advanceHead(void);
	void advanceTail(void);
};

#endif /* QUEUE_H_ */
