#include "../sum.hpp"
#include <gtest/gtest.h>

TEST(InvalidArgument, sum) {
  const char* input[] = { "5a", "1.4", "1" };

  EXPECT_THROW({
    try {
      sum(sizeof(input) / sizeof(char*), input);
    } catch (ArgumentIsNotANumber e ) {
      EXPECT_STREQ("The argument 1: '5a' is not a valid number", e.what() );
      throw;
    };
  }, ArgumentIsNotANumber );

}
