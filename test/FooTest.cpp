/*
 * foo_test.cpp
 *
 *  Created on: 08-Aug-2020
 *      Author: am
 */

#include "gtest/gtest.h"
#include "Foo.h"

namespace {
class FooTest: public ::testing::Test {
protected:
	Foo foo;
};
TEST_F(FooTest, Foo) {
	ASSERT_TRUE(foo.foo());
}
}

