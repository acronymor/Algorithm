#include "array/lc_2373_largest_local_values.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class LargestLocalTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new LargestLocal(); }

  void TearDown() override { delete exec; }

 protected:
  LargestLocal* exec{nullptr};
};

TEST_F(LargestLocalTest, solve) {
  std::vector<std::vector<int>> nums1 = {{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};
  std::vector<std::vector<int>> res1 = exec->solve(nums1);
  ASSERT_EQ(9, res1[0][0]);
  ASSERT_EQ(9, res1[0][1]);
  ASSERT_EQ(8, res1[1][0]);
  ASSERT_EQ(6, res1[1][1]);
}
}  // namespace array
}  // namespace algo