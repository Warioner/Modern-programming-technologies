#include "order_calc.h"
#include <gtest/gtest.h>

TEST(applyDiscount, test1) { EXPECT_EQ(applyDiscount(-5, false), -1); }
TEST(applyDiscount, test2) { EXPECT_EQ(applyDiscount(12000, true), 9600); }
TEST(applyDiscount, test3) { EXPECT_EQ(applyDiscount(12000, false), 10200); }
TEST(applyDiscount, test4) { EXPECT_EQ(applyDiscount(8000, true), 7200); }
TEST(applyDiscount, test5) { EXPECT_EQ(applyDiscount(8000, false), 7600); }
TEST(applyDiscount, test6) { EXPECT_EQ(applyDiscount(4000, false), 4000); }

TEST(calcShipping, test1) { EXPECT_EQ(calcShipping(-5), -1.0); }
TEST(calcShipping, test2) { EXPECT_EQ(calcShipping(7000), 0); }
TEST(calcShipping, test3) { EXPECT_EQ(calcShipping(2000), 300); }