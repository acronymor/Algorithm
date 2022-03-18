#include "math/lc_202_happy_number.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class IsHappyTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new IsHappy(); }

  void TearDown() override { delete exec; }

 protected:
  IsHappy* exec{nullptr};
};

TEST_F(IsHappyTest, isAnagram) {
  int n1 = 19;
  ASSERT_TRUE(exec->isHappy(n1));

  int n2 = 2;
  ASSERT_FALSE(exec->isHappy(n2));
}
}  // namespace math
}  // namespace algo
