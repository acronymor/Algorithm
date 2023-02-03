#include "array/lc_139_word_break.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class WordBreakTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new WordBreak(); }

  void TearDown() override { delete exec; }

 protected:
  WordBreak* exec{nullptr};
};

TEST_F(WordBreakTest, solve) {
  std::string s1 = "leetcode";
  std::vector<std::string> dict1 = {"leet", "code"};
  ASSERT_TRUE(exec->solve(s1, dict1));

  std::string s2 = "applepenapple";
  std::vector<std::string> dict2 = {"apple", "pen"};
  ASSERT_TRUE(exec->solve(s2, dict2));

  std::string s3 = "catsandog";
  std::vector<std::string> dict3 = {"cats", "dog", "sand", "and", "cat"};
  ASSERT_FALSE(exec->solve(s3, dict3));

  std::string s4 = "aaaaaaa";
  std::vector<std::string> dict4 = {"aaaa", "aaa"};
  ASSERT_TRUE(exec->solve(s4, dict4));
};
}  // namespace array
};  // namespace algo
