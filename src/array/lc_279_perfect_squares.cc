#include "array/lc_279_perfect_squares.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class NumSquaresTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new NumSquares(); }

  void TearDown() override { delete exec; }

 protected:
  NumSquares* exec{nullptr};
};

TEST_F(NumSquaresTest, numSquares) {
  ASSERT_EQ(3, exec->numSquares(12));
  ASSERT_EQ(2, exec->numSquares(13));
};
}  // namespace array
};  // namespace algo
