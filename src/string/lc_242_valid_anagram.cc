#include "string/lc_242_valid_anagram.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class IsAnagramTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new IsAnagram(); }

  void TearDown() override { delete exec; }

 protected:
  IsAnagram* exec{nullptr};
};

TEST_F(IsAnagramTest, isAnagram) {
  std::string s1 = "anagram", t1 = "nagaram";
  ASSERT_TRUE(exec->isAnagram(s1, t1));

  std::string s2 = "rat", t2 = "car";
  ASSERT_FALSE(exec->isAnagram(s2, t2));
}
}  // namespace string
}  // namespace algo
