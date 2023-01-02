#include "string/lc_131_palindrome_partitioning.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class PalindromeSubStringTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new PalindromeSubString(); }

  void TearDown() override { delete exec; }

 protected:
  PalindromeSubString* exec{nullptr};
};

TEST_F(PalindromeSubStringTest, partition) {
  std::string s1 = "aab";
  std::vector<std::vector<std::string>> res1 = exec->partition(s1);
  ASSERT_EQ("a", res1[0][0]);
  ASSERT_EQ("a", res1[0][1]);
  ASSERT_EQ("b", res1[0][2]);

  std::string s2 = "a";
  std::vector<std::vector<std::string>> res2 = exec->partition(s2);
  ASSERT_EQ("a", res2[0][0]);
}
}  // namespace string
}  // namespace algo