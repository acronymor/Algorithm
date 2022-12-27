#include "string/lc_32_longest_valid_parentheses.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class LongestValidParenthesesTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new LongestValidParentheses(); }

  void TearDown() override { delete exec; }

 protected:
  LongestValidParentheses* exec{nullptr};
};

TEST_F(LongestValidParenthesesTest, longestValidParentheses1) {
  std::string s1 = "(()";
  int res1 = exec->longestValidParentheses1(s1);
  ASSERT_EQ(2, res1);

  std::string s2 = ")()())";
  int res2 = exec->longestValidParentheses1(s2);
  ASSERT_EQ(4, res2);

  std::string s3 = "";
  int res3 = exec->longestValidParentheses1(s3);
  ASSERT_EQ(0, res3);
}

TEST_F(LongestValidParenthesesTest, longestValidParentheses2) {
  std::string s1 = "(()";
  int res1 = exec->longestValidParentheses2(s1);
  ASSERT_EQ(2, res1);

  std::string s2 = ")()())";
  int res2 = exec->longestValidParentheses2(s2);
  ASSERT_EQ(4, res2);

  std::string s3 = "";
  int res3 = exec->longestValidParentheses2(s3);
  ASSERT_EQ(0, res3);
}
}  // namespace string
}  // namespace algo
