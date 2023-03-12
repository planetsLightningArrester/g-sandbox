#include "../sum.hpp"
#include <gtest/gtest.h>

TEST(SingleArgument, sum) {
  const char* input[] = { "5", "1.4", "1" };
  EXPECT_EQ(7.4, sum(sizeof(input) / sizeof(char*), input));
}
