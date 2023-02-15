#include "string/lc_392_is_subsequence.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class IsSubsequenceTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new IsSubsequence(); }

  void TearDown() override { delete exec; }

 protected:
  IsSubsequence* exec{nullptr};
};

TEST_F(IsSubsequenceTest, solve) {
  ASSERT_TRUE(exec->solve("abc", "ahbgdc"));
  ASSERT_FALSE(exec->solve("axc", "ahbgdc"));
};
};  // namespace string
}  // namespace algo