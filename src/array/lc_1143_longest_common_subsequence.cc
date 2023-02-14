#include "array/lc_1143_longest_common_subsequence.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class LongestCommonSubsequenceTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new LongestCommonSubsequence(); }

  void TearDown() override { delete exec; }

 protected:
  LongestCommonSubsequence* exec{nullptr};
};

TEST_F(LongestCommonSubsequenceTest, solve) {
  ASSERT_EQ(3, exec->solve("abcde", "ace"));
  ASSERT_EQ(3, exec->solve("abc", "abc"));
  ASSERT_EQ(0, exec->solve("abc", "def"));
};
};  // namespace array
}  // namespace algo