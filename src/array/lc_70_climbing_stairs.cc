#include "array/lc_70_climbing_stairs.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class ClimbStairsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new ClimbStairs(); }

  void TearDown() override { delete exec; }

 protected:
  ClimbStairs* exec{nullptr};
};

TEST_F(ClimbStairsTest, climbStairs) {
  ASSERT_EQ(1, exec->climbStairs(1));
  ASSERT_EQ(2, exec->climbStairs(2));
  ASSERT_EQ(3, exec->climbStairs(3));
};
}  // namespace array
};  // namespace algo
