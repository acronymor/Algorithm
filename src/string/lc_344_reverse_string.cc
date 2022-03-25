#include "string/lc_344_reverse_string.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class ReverseStringTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new ReverseString(); }

  void TearDown() override { delete exec; }

 protected:
  ReverseString* exec{nullptr};
};

TEST_F(ReverseStringTest, reverseString) {
  std::vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
  exec->reverseString(s1);
  ASSERT_EQ('o', s1[0]);
  ASSERT_EQ('h', s1[4]);

  std::vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
  exec->reverseString(s2);
  ASSERT_EQ('h', s2[0]);
  ASSERT_EQ('H', s2[5]);
}
}  // namespace string
}  // namespace algo