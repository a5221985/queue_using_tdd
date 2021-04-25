/*
 * foo_test.cpp
 *
 *  Created on: 08-Aug-2020
 *      Author: am
 */

#include <queue.h>
#include <stdexcept>
#include "gtest/gtest.h"

namespace {
class QueueTest: public ::testing::Test {
protected:
	Queue<int, 1> *queue;
	Queue<char, 3> *cQueue;

	virtual void SetUp() {
		queue = new Queue<int, 1>();
		cQueue = new Queue<char, 3>();
	}

	virtual void TearDown() {
		delete queue;
		delete cQueue;
	}
};

TEST_F(QueueTest, ifNewQueue_itIsEmpty) {
	ASSERT_TRUE(queue->isEmpty());
}

TEST_F(QueueTest, ifElementIsEnqueuedIntoNewQueue_itIsNonEmpty) {
	queue->enqueue(25);

	ASSERT_FALSE(queue->isEmpty());
}

TEST_F(QueueTest, ifDequeuedFromEmptyQueue_itThrowsException) {
	try {
		queue->dequeue();

		ASSERT_TRUE(false);
	} catch (std::out_of_range const &err) {
		EXPECT_EQ(err.what(), std::string("Out of range"));
	}
}

TEST_F(QueueTest, ifElementIsEnqueuedDequeuedIntoNewQueue_itMustMatch) {
	queue->enqueue(25);

	ASSERT_EQ(25, queue->dequeue());
	ASSERT_TRUE(queue->isEmpty());

	queue->enqueue(48);

	ASSERT_EQ(48, queue->dequeue());
	ASSERT_TRUE(queue->isEmpty());
}

TEST_F(QueueTest, ifTwoElementsAreEnqueuedDequeuedIntoNewQueue_theyMustMatch) {
	queue->enqueue(25);
	queue->enqueue(48);

	ASSERT_EQ(25, queue->dequeue());
	ASSERT_EQ(48, queue->dequeue());
	ASSERT_TRUE(queue->isEmpty());
}

TEST_F(QueueTest, ifQueueIsMadeFullAndAllElementsRemoved_MoreElementsCanBeAdded) {
	queue->enqueue(25);
	queue->enqueue(48);

	queue->dequeue();
	queue->dequeue();

	queue->enqueue(76);
	queue->enqueue(89);

	ASSERT_EQ(76, queue->dequeue());
	ASSERT_EQ(89, queue->dequeue());
	ASSERT_TRUE(queue->isEmpty());
}

TEST_F(QueueTest, ifQueueIsFullAndMoreElementsAdded_QueueAccomodatesThem) {
	queue->enqueue(25);
	queue->enqueue(48);
	queue->enqueue(76);
	queue->enqueue(89);
	queue->enqueue(1);
	queue->enqueue(4);

	ASSERT_EQ(25, queue->dequeue());
	ASSERT_EQ(48, queue->dequeue());
	ASSERT_EQ(76, queue->dequeue());
	ASSERT_EQ(89, queue->dequeue());
	ASSERT_EQ(1, queue->dequeue());
	ASSERT_EQ(4, queue->dequeue());
	ASSERT_TRUE(queue->isEmpty());
}

TEST_F(QueueTest, ifQueueIsFullAndFewElementsRemovedAndFewAdded_QueueTakesThem) {
	queue->enqueue(25);
	queue->enqueue(48);
	queue->enqueue(76);
	queue->enqueue(89);
	queue->enqueue(1);
	queue->enqueue(4);

	ASSERT_EQ(25, queue->dequeue());
	ASSERT_EQ(48, queue->dequeue());
	ASSERT_EQ(76, queue->dequeue());

	queue->enqueue(5);
	queue->enqueue(6);
	queue->enqueue(7);

	ASSERT_EQ(89, queue->dequeue());
	ASSERT_EQ(1, queue->dequeue());
	ASSERT_EQ(4, queue->dequeue());
	ASSERT_EQ(5, queue->dequeue());
	ASSERT_EQ(6, queue->dequeue());
	ASSERT_EQ(7, queue->dequeue());
	ASSERT_TRUE(queue->isEmpty());
}

TEST_F(QueueTest, charQueue_takesCharItems) {
	cQueue->enqueue('a');
	cQueue->enqueue('b');

	ASSERT_EQ('a', cQueue->dequeue());
	ASSERT_EQ('b', cQueue->dequeue());
	ASSERT_TRUE(cQueue->isEmpty());
}
}

