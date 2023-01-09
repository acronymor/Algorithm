#include "math/lc_738_monotone_digits.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class MonotoneIncreasingDigitsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MonotoneIncreasingDigits(); }

  void TearDown() override { delete exec; }

 protected:
  MonotoneIncreasingDigits* exec{nullptr};
};

TEST_F(MonotoneIncreasingDigitsTest, solve1) {
  ASSERT_EQ(9, exec->solve1(10));
  ASSERT_EQ(1234, exec->solve1(1234));
  ASSERT_EQ(299, exec->solve1(332));
}

TEST_F(MonotoneIncreasingDigitsTest, solve2) {
  ASSERT_EQ(9, exec->solve2(10));
  ASSERT_EQ(1234, exec->solve2(1234));
  ASSERT_EQ(299, exec->solve2(332));
}
}  // namespace math
}  // namespace algo
