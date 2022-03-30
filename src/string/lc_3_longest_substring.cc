#include "string/lc_3_longest_substring.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class LengthOfLongestSubstringTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new LengthOfLongestSubstring(); }

  void TearDown() override { delete exec; }

 protected:
  LengthOfLongestSubstring* exec{nullptr};
};

TEST_F(LengthOfLongestSubstringTest, lengthOfLongestSubstring) {
  std::string s1 = "abcabcbb";
  ASSERT_EQ(3, exec->lengthOfLongestSubstring(s1));

  std::string s2 = "bbbbb";
  ASSERT_EQ(1, exec->lengthOfLongestSubstring(s2));

  std::string s3 = "pwwkew";
  ASSERT_EQ(3, exec->lengthOfLongestSubstring(s3));
};
}  // namespace string
}  // namespace algo
