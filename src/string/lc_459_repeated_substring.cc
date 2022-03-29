#include "string/lc_459_repeated_substring.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class RepeatedSubstringTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new RepeatedSubstring(); }

  void TearDown() override { delete exec; }

 protected:
  RepeatedSubstring* exec{nullptr};
};

TEST_F(RepeatedSubstringTest, reverseString1) {
  std::string s1 = "abab";
  ASSERT_TRUE(exec->repeatedSubstringPattern1(s1));

  std::string s2 = "aba";
  ASSERT_FALSE(exec->repeatedSubstringPattern1(s2));

  std::string s3 = "abcabcabcabc";
  ASSERT_TRUE(exec->repeatedSubstringPattern1(s3));

  std::string s4 = "ababba";
  ASSERT_FALSE(exec->repeatedSubstringPattern1(s4));
}

TEST_F(RepeatedSubstringTest, reverseString2) {
  std::string s1 = "abab";
  ASSERT_TRUE(exec->repeatedSubstringPattern2(s1));

  std::string s2 = "aba";
  ASSERT_FALSE(exec->repeatedSubstringPattern2(s2));

  std::string s3 = "abcabcabcabc";
  ASSERT_TRUE(exec->repeatedSubstringPattern2(s3));

  std::string s4 = "ababba";
  ASSERT_FALSE(exec->repeatedSubstringPattern2(s4));
}
}  // namespace string
}  // namespace algo
