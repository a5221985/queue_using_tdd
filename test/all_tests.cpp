/*
 * all_tests.cpp
 *
 *  Created on: 08-Aug-2020
 *      Author: am
 */

#include <queue.h>
#include "gtest/gtest.h"

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
