#include "string/lc_72_min_distance.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class MinDistinctTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MinDistinct(); }

  void TearDown() override { delete exec; }

 protected:
  MinDistinct* exec{nullptr};
};

TEST_F(MinDistinctTest, solve) {
  ASSERT_EQ(3, exec->solve("horse", "ros"));
  ASSERT_EQ(5, exec->solve("intention", "execution"));
};
};  // namespace string
}  // namespace algo