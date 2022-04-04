#include "string/lc_20_valid_parentheses.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class IsValidTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new IsValid(); }

  void TearDown() override { delete exec; }

 protected:
  IsValid* exec{nullptr};
};

TEST_F(IsValidTest, isValid1) {
  std::string s1 = "()";
  ASSERT_TRUE(exec->isValid1(s1));

  std::string s2 = "()[]{}";
  ASSERT_TRUE(exec->isValid1(s2));

  std::string s3 = "(]";
  ASSERT_FALSE(exec->isValid1(s3));

  std::string s4 = "]";
  ASSERT_FALSE(exec->isValid1(s4));
}

TEST_F(IsValidTest, isValid2) {
  std::string s1 = "()";
  ASSERT_TRUE(exec->isValid2(s1));

  std::string s2 = "()[]{}";
  ASSERT_TRUE(exec->isValid2(s2));

  std::string s3 = "(]";
  ASSERT_FALSE(exec->isValid2(s3));

  std::string s4 = "]";
  ASSERT_FALSE(exec->isValid2(s4));
}

}  // namespace string
}  // namespace algo
