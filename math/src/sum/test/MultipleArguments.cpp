#include "../sum.hpp"
#include <gtest/gtest.h>

TEST(MultipleArguments, sum) {
  const char* input[] = { "1", "1.4", "1" };
  EXPECT_EQ(3.4, sum(sizeof(input) / sizeof(char*), input));
}
