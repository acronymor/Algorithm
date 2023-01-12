#include "math/lc_343_integer_break.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class IntegerBreakTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new IntegerBreak(); }

  void TearDown() override { delete exec; }

 protected:
  IntegerBreak* exec{nullptr};
};

TEST_F(IntegerBreakTest, solve) {
  ASSERT_EQ(1, exec->solve(2));
  ASSERT_EQ(36, exec->solve(10));
}

}  // namespace math
}  // namespace algo
