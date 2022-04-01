#include "string/lc_5_longest_palindromic_substring.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class LongestPalindromeTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new LongestPalindrome(); }

  void TearDown() override { delete exec; }

 protected:
  LongestPalindrome* exec{nullptr};
};

TEST_F(LongestPalindromeTest, longestPalindrome1) {
  std::string s1 = "babad";
  ASSERT_EQ("aba", exec->longestPalindrome1(s1));

  std::string s2 = "cbbd";
  ASSERT_EQ("bb", exec->longestPalindrome1(s2));
};

TEST_F(LongestPalindromeTest, longestPalindrome2) {
  std::string s1 = "babad";
  ASSERT_EQ("bab", exec->longestPalindrome2(s1));

  std::string s2 = "cbbd";
  ASSERT_EQ("bb", exec->longestPalindrome2(s2));
};
}  // namespace string
}  // namespace algo
