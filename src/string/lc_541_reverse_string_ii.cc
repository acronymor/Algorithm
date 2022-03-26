#include "string/lc_541_reverse_string_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class ReverseStringIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new ReverseStringII(); }

  void TearDown() override { delete exec; }

 protected:
  ReverseStringII* exec{nullptr};
};

TEST_F(ReverseStringIITest, reverseString) {
  std::string s1 = "abcdefg";
  std::string res1 = exec->reverseString(s1, 2);
  ASSERT_EQ('b', res1[0]);
  ASSERT_EQ('a', res1[1]);
  ASSERT_EQ('g', res1[6]);

  std::string s2 = "abcd";
  std::string res2 = exec->reverseString(s2, 2);
  ASSERT_EQ('b', res2[0]);
  ASSERT_EQ('a', res2[1]);
  ASSERT_EQ('d', res2[3]);
}
}  // namespace string
}  // namespace algo