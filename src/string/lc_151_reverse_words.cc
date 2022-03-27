#include "string/lc_151_reverse_words.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class ReverseWordsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new ReverseWords(); }

  void TearDown() override { delete exec; }

 protected:
  ReverseWords* exec{nullptr};
};

TEST_F(ReverseWordsTest, reverseWords) {
  std::string s1 = "the sky is blue";
  std::string target1 = "blue is sky the";
  std::string res1 = exec->reverseWords(s1);
  ASSERT_EQ(target1, res1);

  std::string s2 = "  hello world  ";
  std::string target2 = "world hello";
  std::string res2 = exec->reverseWords(s2);
  ASSERT_EQ(target2, res2);

  std::string s3 = "a good   example";
  std::string target3 = "example good a";
  std::string res3 = exec->reverseWords(s3);
  ASSERT_EQ(target3, res3);
}
}  // namespace string
}  // namespace algo
