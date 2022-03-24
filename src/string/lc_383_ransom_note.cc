#include "string/lc_383_ransom_note.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class CanConstructTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new CanConstruct(); }

  void TearDown() override { delete exec; }

 protected:
  CanConstruct* exec{nullptr};
};

TEST_F(CanConstructTest, canConstruct) {
  ASSERT_FALSE(exec->canConstruct("a", "b"));
  ASSERT_TRUE(exec->canConstruct("aa", "aab"));
}
}  // namespace string
}  // namespace algo
