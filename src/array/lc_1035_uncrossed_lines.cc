#include "array/lc_1035_uncrossed_lines.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MaxUncrossedLinesTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MaxUncrossedLines(); }

  void TearDown() override { delete exec; }

 protected:
  MaxUncrossedLines* exec{nullptr};
};

TEST_F(MaxUncrossedLinesTest, solve) {
  ASSERT_EQ(2, exec->solve({1, 4, 2}, {1, 2, 4}));
  ASSERT_EQ(3, exec->solve({2, 5, 1, 2, 5}, {10, 5, 2, 1, 5, 2}));
  ASSERT_EQ(2, exec->solve({1, 3, 7, 1, 7, 5}, {1, 9, 2, 5, 1}));
};
};  // namespace array
}  // namespace algo
