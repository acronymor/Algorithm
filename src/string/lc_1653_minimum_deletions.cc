#include "lc_1653_minimum_deletions.h"

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

TEST_F(MinDistanceTest, solve1) {
  int res1 = exec->solve1("aababbab");
  ASSERT_EQ(2, res1);

  int res2 = exec->solve1("bbaaaaabb");
  ASSERT_EQ(2, res2);
}

TEST_F(MinDistanceTest, solve2) {
  int res1 = exec->solve2("aababbab");
  ASSERT_EQ(2, res1);

  int res2 = exec->solve2("bbaaaaabb");
  ASSERT_EQ(2, res2);
}
}  // namespace string
}  // namespace algo