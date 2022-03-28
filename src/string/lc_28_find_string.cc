#include "string/lc_28_find_string.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class StrStrTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new StrStr(); }

  void TearDown() override { delete exec; }

 protected:
  StrStr* exec{nullptr};
};

TEST_F(StrStrTest, strStr1) {
  std::string s1 = "sadbutsad";
  std::string n1 = "sad";
  int res1 = exec->strStr1(s1, n1);
  ASSERT_EQ(0, res1);

  std::string s2 = "leetcode";
  std::string n2 = "leeto";
  int res2 = exec->strStr1(s2, n2);
  ASSERT_EQ(-1, res2);
}

TEST_F(StrStrTest, strStr2) {
  std::string s1 = "sadbutsad";
  std::string n1 = "sad";
  int res1 = exec->strStr2(s1, n1);
  ASSERT_EQ(0, res1);

  std::string s2 = "leetcode";
  std::string n2 = "leeto";
  int res2 = exec->strStr2(s2, n2);
  ASSERT_EQ(-1, res2);
}

TEST_F(StrStrTest, strStr3) {
  std::string s1 = "sadbutsad";
  std::string n1 = "sad";
  int res1 = exec->strStr3(s1, n1);
  ASSERT_EQ(0, res1);

  std::string s2 = "leetcode";
  std::string n2 = "leeto";
  int res2 = exec->strStr3(s2, n2);
  ASSERT_EQ(-1, res2);
}

}  // namespace string
}  // namespace algo