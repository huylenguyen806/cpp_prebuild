#include <gtest/gtest.h>

TEST(demotest, demo) {
	EXPECT_EQ(1, 1) << "This is true" << std::endl;
	EXPECT_NE(1, 2) << "This is false" << std::endl;
}