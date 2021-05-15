/*
 * Main.cpp
 *
 *  Created on: 09-Aug-2020
 *      Author: am
 */

#include <stdio.h>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

