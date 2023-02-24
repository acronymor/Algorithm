#include "string/lc_583_min_distance.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class MinDistanceTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MinDistance(); }

  void TearDown() override { delete exec; }

 protected:
  MinDistance* exec{nullptr};
};

TEST_F(MinDistanceTest, minDistance) {
  int res1 = exec->solve("sea", "eat");
  ASSERT_EQ(2, res1);

  int res2 = exec->solve("leetcode", "etco");
  ASSERT_EQ(4, res2);
}
}  // namespace string
}  // namespace algo
